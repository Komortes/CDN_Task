#include "Trie.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *duplicateRange(const char *start, size_t length) {
    char *copy = malloc(length + 1);
    if (copy == NULL) {
        return NULL;
    }

    memcpy(copy, start, length);
    copy[length] = '\0';
    return copy;
}

static void freeLabels(char **labels, size_t count) {
    if (labels == NULL) {
        return;
    }

    for (size_t i = 0; i < count; ++i) {
        free(labels[i]);
    }
    free(labels);
}

static char **splitLabels(const char *name, size_t *count) {
    size_t label_count = 1;
    for (const char *cursor = name; *cursor != '\0'; ++cursor) {
        if (*cursor == '.') {
            label_count++;
        }
    }

    char **labels = calloc(label_count, sizeof(char *));
    if (labels == NULL) {
        return NULL;
    }

    size_t index = 0;
    const char *segment_start = name;
    for (const char *cursor = name;; ++cursor) {
        if (*cursor != '.' && *cursor != '\0') {
            continue;
        }

        size_t length = (size_t)(cursor - segment_start);
        labels[index] = duplicateRange(segment_start, length);
        if (labels[index] == NULL) {
            freeLabels(labels, index);
            return NULL;
        }
        index++;

        if (*cursor == '\0') {
            break;
        }

        segment_start = cursor + 1;
    }

    *count = index;
    return labels;
}

static struct LabelNode *createLabelNode(const char *label) {
    struct LabelNode *node = calloc(1, sizeof(struct LabelNode));
    if (node == NULL) {
        return NULL;
    }

    if (label != NULL) {
        node->label = duplicateRange(label, strlen(label));
        if (node->label == NULL) {
            free(node);
            return NULL;
        }
    }

    return node;
}

static struct LabelNode *findChild(struct LabelNode *parent, const char *label) {
    for (struct LabelNode *child = parent->child; child != NULL; child = child->sibling) {
        if (strcmp(child->label, label) == 0) {
            return child;
        }
    }

    return NULL;
}

static struct LabelNode *getOrCreateChild(struct LabelNode *parent, const char *label) {
    struct LabelNode *child = findChild(parent, label);
    if (child != NULL) {
        return child;
    }

    child = createLabelNode(label);
    if (child == NULL) {
        fprintf(stderr, "Failed to allocate label node\n");
        return NULL;
    }

    child->sibling = parent->child;
    parent->child = child;
    return child;
}

static int insertForward(struct LabelNode *root, char **labels, size_t start, size_t end) {
    struct LabelNode *current = root;
    for (size_t i = start; i < end; ++i) {
        current = getOrCreateChild(current, labels[i]);
        if (current == NULL) {
            return 0;
        }
    }

    current->terminal = 1;
    return 1;
}

static int insertReverse(struct LabelNode *root, char **labels, size_t start, size_t end) {
    struct LabelNode *current = root;
    for (size_t i = end; i > start; --i) {
        current = getOrCreateChild(current, labels[i - 1]);
        if (current == NULL) {
            return 0;
        }
    }

    current->terminal = 1;
    return 1;
}

static char **duplicateLabels(char **labels, size_t count) {
    char **copy = calloc(count, sizeof(char *));
    if (copy == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < count; ++i) {
        copy[i] = duplicateRange(labels[i], strlen(labels[i]));
        if (copy[i] == NULL) {
            freeLabels(copy, i);
            return NULL;
        }
    }

    return copy;
}

static int addMiddlePattern(struct TrieNode *root, char **labels, size_t wildcard_index, size_t label_count) {
    struct MiddlePattern *pattern = calloc(1, sizeof(struct MiddlePattern));
    if (pattern == NULL) {
        fprintf(stderr, "Failed to allocate middle wildcard pattern\n");
        return 0;
    }

    pattern->prefix_count = wildcard_index;
    pattern->suffix_count = label_count - wildcard_index - 1;
    pattern->prefix_labels = duplicateLabels(labels, pattern->prefix_count);
    pattern->suffix_labels = duplicateLabels(labels + wildcard_index + 1, pattern->suffix_count);

    if ((pattern->prefix_count > 0 && pattern->prefix_labels == NULL) ||
        (pattern->suffix_count > 0 && pattern->suffix_labels == NULL)) {
        freeLabels(pattern->prefix_labels, pattern->prefix_count);
        freeLabels(pattern->suffix_labels, pattern->suffix_count);
        free(pattern);
        fprintf(stderr, "Failed to store middle wildcard pattern\n");
        return 0;
    }

    pattern->next = root->middle_patterns;
    root->middle_patterns = pattern;
    return 1;
}

static void freeLabelTrie(struct LabelNode *node) {
    if (node == NULL) {
        return;
    }

    freeLabelTrie(node->child);
    freeLabelTrie(node->sibling);
    free(node->label);
    free(node);
}

static void freeMiddlePatterns(struct MiddlePattern *pattern) {
    while (pattern != NULL) {
        struct MiddlePattern *next = pattern->next;
        freeLabels(pattern->prefix_labels, pattern->prefix_count);
        freeLabels(pattern->suffix_labels, pattern->suffix_count);
        free(pattern);
        pattern = next;
    }
}

static int matchExact(struct LabelNode *root, char **labels, size_t count) {
    struct LabelNode *current = root;
    for (size_t i = 0; i < count; ++i) {
        current = findChild(current, labels[i]);
        if (current == NULL) {
            return 0;
        }
    }

    return current->terminal;
}

static int matchLeadingWildcard(struct LabelNode *root, char **labels, size_t count) {
    struct LabelNode *current = root;
    size_t consumed = 0;

    for (size_t i = count; i > 0; --i) {
        current = findChild(current, labels[i - 1]);
        if (current == NULL) {
            return 0;
        }

        consumed++;
        if (current->terminal && count > consumed) {
            return 1;
        }
    }

    return 0;
}

static int matchTrailingWildcard(struct LabelNode *root, char **labels, size_t count) {
    struct LabelNode *current = root;

    for (size_t i = 0; i < count; ++i) {
        current = findChild(current, labels[i]);
        if (current == NULL) {
            return 0;
        }

        if (current->terminal && count > i + 1) {
            return 1;
        }
    }

    return 0;
}

static int labelsEqual(char **left, char **right, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        if (strcmp(left[i], right[i]) != 0) {
            return 0;
        }
    }

    return 1;
}

static int matchMiddleWildcard(struct MiddlePattern *patterns, char **labels, size_t count) {
    for (const struct MiddlePattern *pattern = patterns; pattern != NULL; pattern = pattern->next) {
        if (count <= pattern->prefix_count + pattern->suffix_count) {
            continue;
        }

        if (!labelsEqual(pattern->prefix_labels, labels, pattern->prefix_count)) {
            continue;
        }

        if (!labelsEqual(pattern->suffix_labels,
                         labels + count - pattern->suffix_count,
                         pattern->suffix_count)) {
            continue;
        }

        return 1;
    }

    return 0;
}

struct TrieNode *getNode(void) {
    struct TrieNode *root = calloc(1, sizeof(struct TrieNode));
    if (root == NULL) {
        fprintf(stderr, "Failed to allocate matcher root\n");
        return NULL;
    }

    root->exact_root = createLabelNode(NULL);
    root->leading_wildcard_root = createLabelNode(NULL);
    root->trailing_wildcard_root = createLabelNode(NULL);

    if (root->exact_root == NULL ||
        root->leading_wildcard_root == NULL ||
        root->trailing_wildcard_root == NULL) {
        deleteTrie(root);
        fprintf(stderr, "Failed to allocate matcher tries\n");
        return NULL;
    }

    return root;
}

void insert(struct TrieNode *root, const char *key) {
    if (root == NULL || key == NULL || key[0] == '\0') {
        return;
    }

    size_t label_count = 0;
    char **labels = splitLabels(key, &label_count);
    if (labels == NULL) {
        fprintf(stderr, "Failed to parse pattern '%s'\n", key);
        return;
    }

    size_t wildcard_count = 0;
    size_t wildcard_index = 0;
    for (size_t i = 0; i < label_count; ++i) {
        if (strcmp(labels[i], "*") == 0) {
            wildcard_count++;
            wildcard_index = i;
        }
    }

    if (wildcard_count == 0) {
        insertForward(root->exact_root, labels, 0, label_count);
    } else if (wildcard_count == 1 && wildcard_index == 0) {
        insertReverse(root->leading_wildcard_root, labels, wildcard_index + 1, label_count);
    } else if (wildcard_count == 1 && wildcard_index == label_count - 1) {
        insertForward(root->trailing_wildcard_root, labels, 0, wildcard_index);
    } else if (wildcard_count == 1) {
        addMiddlePattern(root, labels, wildcard_index, label_count);
    } else {
        fprintf(stderr, "Skipping unsupported pattern with multiple wildcards: %s\n", key);
    }

    freeLabels(labels, label_count);
}

int search(struct TrieNode *root, const char *key) {
    if (root == NULL || key == NULL || key[0] == '\0') {
        return 0;
    }

    size_t label_count = 0;
    char **labels = splitLabels(key, &label_count);
    if (labels == NULL) {
        fprintf(stderr, "Failed to parse hostname '%s'\n", key);
        return 0;
    }

    int matched = matchExact(root->exact_root, labels, label_count) ||
                  matchLeadingWildcard(root->leading_wildcard_root, labels, label_count) ||
                  matchTrailingWildcard(root->trailing_wildcard_root, labels, label_count) ||
                  matchMiddleWildcard(root->middle_patterns, labels, label_count);

    freeLabels(labels, label_count);
    return matched;
}

void deleteTrie(struct TrieNode *root) {
    if (root == NULL) {
        return;
    }

    freeLabelTrie(root->exact_root);
    freeLabelTrie(root->leading_wildcard_root);
    freeLabelTrie(root->trailing_wildcard_root);
    freeMiddlePatterns(root->middle_patterns);
    free(root);
}

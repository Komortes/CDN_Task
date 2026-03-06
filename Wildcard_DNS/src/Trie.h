#ifndef WILDCARD_DNS_TRIE_H
#define WILDCARD_DNS_TRIE_H

#include <stddef.h>

struct LabelNode {
    char *label;
    int terminal;
    struct LabelNode *child;
    struct LabelNode *sibling;
};

struct MiddlePattern {
    char **prefix_labels;
    size_t prefix_count;
    char **suffix_labels;
    size_t suffix_count;
    struct MiddlePattern *next;
};

struct TrieNode {
    struct LabelNode *exact_root;
    struct LabelNode *leading_wildcard_root;
    struct LabelNode *trailing_wildcard_root;
    struct MiddlePattern *middle_patterns;
};

struct TrieNode *getNode(void);
void insert(struct TrieNode *root, const char *key);
int search(struct TrieNode *root, const char *key);
void deleteTrie(struct TrieNode *root);

#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Trie.h"
#define DEBUG 0

int CHAR_TO_INDEX(char c) { return (int)c; }

struct TrieNode *getNode(void) {
    struct TrieNode *node = malloc(sizeof(struct TrieNode));
    if (!node) {
        fprintf(stderr, "Failed to allocate memory for TrieNode\n");
        return NULL;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    node->endOfWord = 0;  
    return node;
}

void insert(struct TrieNode *root, const char *key) {
    struct TrieNode *pNode = root;
    int length = strlen(key);
    for (int level = 0; level < length; level++) {
        if (key[level] == '*' && level == 0) {
            continue;
        }
        int index = CHAR_TO_INDEX(key[level]);
        if (!pNode->children[index]) {
            pNode->children[index] = getNode();
            if (!pNode->children[index]) {
                fprintf(stderr, "Failed to allocate memory for TrieNode\n");
                return;
            }
        }
        pNode = pNode->children[index];
        if (key[level] == '.') {
            pNode->endOfWord = 1;
        }
    }
    pNode->endOfWord = 1;
}

int search(struct TrieNode *root, const char *key) {
    struct TrieNode *pNode = root;
    int length = strlen(key);
    int level;
    int start = 0;

    while (start < length) {
        pNode = root;
        for (level = start; level < length; level++) {
            int index = CHAR_TO_INDEX(key[level]);
            if (!pNode->children[index]){
                if (pNode->children[CHAR_TO_INDEX('*')]) {
                    if (DEBUG) printf("Match found for '%s'\n", key);
                    return 1;
                }
                break;
            }
            pNode = pNode->children[index];
        }

        if (level == length && pNode != NULL && pNode->endOfWord ) {
            if (DEBUG) printf("Match found for '%s' on\n", key);
            return 1;
        }
        start++;
    }

    if (DEBUG) printf("No match found for '%s'\n", key);
    return 0;
}


void deleteTrie(struct TrieNode* root) {
    if (!root)
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        deleteTrie(root->children[i]);
    free(root);
}

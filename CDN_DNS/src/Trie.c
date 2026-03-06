#include "Trie.h"
#include <stdio.h>
#include <stdlib.h>

#define IPV6_BITS 128

Node* createNode(int pop, int scope) {
    Node* node = calloc(1, sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Failed to allocate trie node\n");
        return NULL;
    }

    node->pop = pop;
    node->scope = scope;
    return node;
}

void insert(Node* root, int pop, int prefix_length, const uint8_t* addr) {
    if (root == NULL || addr == NULL || prefix_length < 0 || prefix_length > IPV6_BITS) {
        return;
    }

    Node* current = root;
    for (int i = 0; i < prefix_length; ++i) {
        int bit = (addr[i / 8] >> (7 - (i % 8))) & 1;
        if (bit == 0) {
            if (current->zero == NULL) {
                current->zero = createNode(-1, i + 1);
                if (current->zero == NULL) {
                    return;
                }
            }
            current = current->zero;
        } else {
            if (current->one == NULL) {
                current->one = createNode(-1, i + 1);
                if (current->one == NULL) {
                    return;
                }
            }
            current = current->one;
        }
    }
    current->pop = pop;
    current->scope = prefix_length;
}

int findBestMatch(Node* root, const uint8_t* addr, int* scope) {
    if (root == NULL || addr == NULL || scope == NULL) {
        return -1;
    }

    Node* current = root;
    Node* bestMatch = NULL;
    for (int i = 0; i < IPV6_BITS; ++i) {
        int bit = (addr[i / 8] >> (7 - (i % 8))) & 1;
        if (current->pop != -1) {
            bestMatch = current;
        }
        if (bit == 0) {
            current = current->zero;
        } else {
            current = current->one;
        }
        if (current == NULL) {
            break;
        }
    }
    if (bestMatch) {
        *scope = bestMatch->scope;
        return bestMatch->pop;
    }
    return -1;
}

void deleteTrie(Node* root) {
    if (root) {
        deleteTrie(root->zero);
        deleteTrie(root->one);
        free(root);
    }
}

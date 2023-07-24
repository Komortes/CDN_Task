#include "Trie.h"
#include <stdlib.h>

#define IPV6_BITS 128

Node* createNode(int pop, int scope) {
    Node* node = malloc(sizeof(Node));
    node->zero = NULL;
    node->one = NULL;
    node->pop = pop;
    node->scope = scope;
    return node;
}

void insert(Node* root, int pop, int prefix_length, uint8_t* addr) {
    Node* current = root;
    for (int i = 0; i < prefix_length; ++i) {
        int bit = (addr[i / 8] >> (7 - (i % 8))) & 1;
        if (bit == 0) {
            if (current->zero == NULL)
                current->zero = createNode(-1, i + 1);
            current = current->zero;
        } else {
            if (current->one == NULL)
                current->one = createNode(-1, i + 1);
            current = current->one;
        }
    }
    current->pop = pop;
}

int findBestMatch(Node* root, uint8_t* addr, int* scope) {
    Node* current = root;
    Node* bestMatch = NULL;
    for (int i = 0; i < IPV6_BITS; ++i) {
        int bit = (addr[i / 8] >> (7 - (i % 8))) & 1;
        if (current->pop != -1)
            bestMatch = current;
        if (bit == 0)
            current = current->zero;
        else
            current = current->one;
        if (current == NULL)
            break;
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

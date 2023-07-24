#ifndef TRIE_H
#define TRIE_H

#include <stdint.h>

typedef struct node {
    struct node *zero, *one;
    int pop;
    int scope;
} Node;

Node* createNode(int pop, int scope);
void insert(Node* root, int pop, int prefix_length, uint8_t subnet[16]);
int findBestMatch(Node* root, uint8_t query[16], int* scope);
void deleteTrie(Node* root);

#endif 

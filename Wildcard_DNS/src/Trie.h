#ifndef TRIE
#define TRIE

#define ALPHABET_SIZE 256 

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int endOfWord;  
};

struct TrieNode *getNode(void);
void insert(struct TrieNode *root, const char *key);
int search(struct TrieNode *root, const char *key);
void deleteTrie(struct TrieNode* root);

#endif

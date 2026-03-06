#include <stdio.h>
#include "Trie.h"
#include "Patterns.h"
#include "Test_Data.h"

int main(void) {
    struct TrieNode *root = getNode();
    if (!root) {
        fprintf(stderr, "Failed to allocate memory for root node\n");
        return 1;
    }

    size_t patterns_size = sizeof(patterns) / sizeof(patterns[0]);
    for (size_t i = 0; i < patterns_size; i++) {
        insert(root, patterns[i].pattern);
    }

    size_t tests_size = sizeof(tests) / sizeof(tests[0]);
    int passed_tests = 0;
    for (size_t i = 0; i < tests_size; i++) {
        int result = search(root, tests[i].address);
        if (result == tests[i].expectedResult) {
            passed_tests++;
        } else {
            printf("Test failed for '%s': expected %d, got %d\n", tests[i].address, tests[i].expectedResult, result);
        }
    }

    printf("Wildcard DNS test run\n");
    printf("Patterns loaded: %zu\n", patterns_size);
    printf("Passed tests: %d out of %zu\n", passed_tests, tests_size);

    deleteTrie(root);
    return passed_tests == (int)tests_size ? 0 : 1;
}

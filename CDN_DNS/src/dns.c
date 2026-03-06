#include "Reader.h"
#include "Trie.h"

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static const char* DEFAULT_DATA_CANDIDATES[] = {
    "routing-data.txt",
    "../build/routing-data.txt",
    "CDN_DNS/build/routing-data.txt",
};

static const char* DEFAULT_QUERIES[] = {
    "2001:49f0:d0b8::",
    "2402:8100:2582:1233:3300::",
    "240e:438:1e30:1aff::",
    "2620:121:7::",
    "240e:44d:6e40:12fa::",
    "2804:2c20:0:3366::",
    "2804:c00:2000:4512::",
    "2620:12c:7::",
    "2a04:4e40:6000:1265::",
    "2a01:4b40:6000:bc12::",
    "2a01:c50f:2ec0:ca67::",
    "2402:8100:288f:ee12::",
    "2804:2c24:0:f823::",
    "2a09:7:2003:f156::",
    "2a02:2e02:2620:1767::",
    "2a00:8a84:a000:e212::",
    "2001:6d0:ffd8:e23::",
    "240e:438:e20:1844::",
    "2a02:2838:0:3366::",
    "2a02:26f7:cec0:7412::",
    "2402:8100:3097:c154::",
    "2409:8904:3490:4c12::",
    "2804:2c3c:0:fa65::",
    "2409:8915:2480:ff32::",
    "2600:6c38:b41:fc0e::",
    "2402:800:321c:22aa::",
    "2406:3003:3022:210f::",
    "2806:20d:321e:f023::",
    "2a02:26f7:cac4:2154::",
    "2001:dc7:ffd3:6403::",
    "2001:1248:7043:2211::",
    "2804:2c30:0:9363::",
    "2a02:26f7:c7c9:3723::",
    "2600:140f:3200:76fa::",
    "2a02:26f7:c6c8:bb12::",
    "2401:4900:3854:f104::",
    "2402:8100:399e:f720::",
    "2a02:2e02:3630:ff10::",
};

static const char* resolveDataPath(const char* cli_path) {
    if (cli_path != NULL) {
        return cli_path;
    }

    size_t candidate_count = sizeof(DEFAULT_DATA_CANDIDATES) / sizeof(DEFAULT_DATA_CANDIDATES[0]);
    for (size_t i = 0; i < candidate_count; ++i) {
        if (access(DEFAULT_DATA_CANDIDATES[i], R_OK) == 0) {
            return DEFAULT_DATA_CANDIDATES[i];
        }
    }

    return DEFAULT_DATA_CANDIDATES[0];
}

static int loadRoutes(Node* root, const char* data_path, int* record_count) {
    int size = 0;
    Record* records = readData(data_path, &size);
    if (records == NULL) {
        return 0;
    }

    for (int i = 0; i < size; ++i) {
        insert(root, records[i].pop, records[i].prefix_length, records[i].subnet);
    }

    free(records);
    *record_count = size;
    return 1;
}

static void printHeader(const char* data_path, int record_count, size_t query_count) {
    printf("CDN DNS longest-prefix match demo\n");
    printf("Dataset: %s\n", data_path);
    printf("Loaded %d routes, processing %zu queries\n\n", record_count, query_count);
}

static int runQueries(Node* root) {
    size_t query_count = sizeof(DEFAULT_QUERIES) / sizeof(DEFAULT_QUERIES[0]);
    int matched = 0;

    for (size_t i = 0; i < query_count; ++i) {
        uint8_t query[16];
        int scope = -1;

        if (inet_pton(AF_INET6, DEFAULT_QUERIES[i], query) != 1) {
            fprintf(stderr, "Skipping invalid query address: %s\n", DEFAULT_QUERIES[i]);
            continue;
        }

        int pop = findBestMatch(root, query, &scope);
        if (pop == -1) {
            printf("%-28s -> no route found\n", DEFAULT_QUERIES[i]);
            continue;
        }

        matched++;
        printf("%-28s -> PoP %3d (/%d)\n", DEFAULT_QUERIES[i], pop, scope);
    }

    printf("\nSummary: %d/%zu queries matched\n", matched, query_count);
    return matched == (int)query_count ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main(int argc, char* argv[]) {
    const char* data_path = resolveDataPath(argc > 1 ? argv[1] : NULL);
    Node* root = createNode(-1, 0);
    if (root == NULL) {
        return EXIT_FAILURE;
    }

    int record_count = 0;
    if (!loadRoutes(root, data_path, &record_count)) {
        deleteTrie(root);
        return EXIT_FAILURE;
    }

    size_t query_count = sizeof(DEFAULT_QUERIES) / sizeof(DEFAULT_QUERIES[0]);
    printHeader(data_path, record_count, query_count);

    int exit_code = runQueries(root);
    deleteTrie(root);
    return exit_code;
}

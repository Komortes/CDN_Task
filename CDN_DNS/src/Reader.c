#include "Reader.h"
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Record* readData(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open routing data '%s': %s\n", filename, strerror(errno));
        return NULL;
    }

    int capacity = 256;
    Record* records = malloc(sizeof(Record) * (size_t)capacity);
    if (records == NULL) {
        fprintf(stderr, "Failed to allocate memory for routing records\n");
        fclose(file);
        return NULL;
    }

    char buffer[256];
    int index = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char subnet_text[INET6_ADDRSTRLEN];
        int prefix_length = 0;
        int pop = 0;

        if (buffer[0] == '\n' || buffer[0] == '\0') {
            continue;
        }

        if (sscanf(buffer, "%45[^/]/%d %d", subnet_text, &prefix_length, &pop) != 3) {
            fprintf(stderr, "Skipping malformed routing record: %s", buffer);
            continue;
        }

        if (prefix_length < 0 || prefix_length > 128) {
            fprintf(stderr, "Skipping invalid prefix length in record: %s", buffer);
            continue;
        }

        if (index == capacity) {
            capacity *= 2;
            Record* resized = realloc(records, sizeof(Record) * (size_t)capacity);
            if (resized == NULL) {
                fprintf(stderr, "Failed to grow routing records buffer\n");
                free(records);
                fclose(file);
                return NULL;
            }
            records = resized;
        }

        if (inet_pton(AF_INET6, subnet_text, records[index].subnet) != 1) {
            fprintf(stderr, "Skipping invalid IPv6 subnet: %s\n", subnet_text);
            continue;
        }

        records[index].prefix_length = prefix_length;
        records[index].pop = pop;
        index++;
    }

    fclose(file);

    *size = index;
    return records;
}

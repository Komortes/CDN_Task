#include "Reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

Record* readData(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    Record* records = malloc(sizeof(Record) * 5000);
    char buffer[256];
    int index = 0;
    
    while (index < 200 && fgets(buffer, sizeof(buffer), file)) {
        char* slashPos = strchr(buffer, '/');
        char* spacePos = strchr(buffer, ' ');
        *slashPos = '\0';
        *spacePos = '\0';

        inet_pton(AF_INET6, buffer, records[index].subnet);
        records[index].prefix_length = atoi(slashPos + 1);
        records[index].pop = atoi(spacePos + 1);

        index++;
    }
    fclose(file);
    
    *size = index;
    return records;
}

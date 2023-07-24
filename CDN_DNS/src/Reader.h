#ifndef CDN_DNS_H
#define CDN_DNS_H

#include <stdint.h>

typedef struct {
    int pop;
    int prefix_length;
    uint8_t subnet[16];
} Record;

Record* readData(const char* filename, int* size);

#endif //CDN_DNS_H

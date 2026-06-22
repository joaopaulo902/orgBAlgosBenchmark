#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif

uint32_t crc32(const uint8_t *data, size_t n_bytes) {
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < n_bytes; i++) {
        crc ^= data[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320;
            } else {
                crc >>= 1;
            }
        }
    }
    return ~crc;
}

int main() {
    uint8_t *data = (uint8_t *)malloc(BUFFER_SIZE);
    for(int i = 0; i < BUFFER_SIZE; i++) data[i] = i % 256;

    uint32_t result = crc32(data, BUFFER_SIZE);
    printf("CRC32 final: %u\n", result);

    free(data);
    return 0;
}
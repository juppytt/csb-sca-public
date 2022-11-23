#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h>

void clflush(const void* addr) {
    asm volatile("clflush 0(%0)\n" :: "r"(addr) : "memory");
}

void load(const void *addr) {
    (uint8_t)*(const volatile uint8_t *)(addr);
}

uint64_t measure(uint8_t* addr) {
    uint64_t begin;
    _mm_lfence();
    begin = __rdtsc();
    _mm_lfence();
    _mm_mfence();
    load(addr);
    _mm_lfence();
    _mm_mfence();

    return __rdtsc() - begin;
}

void hex_dump(const uint8_t *data, uint32_t size) {
    int32_t remaining = (int32_t) size, offset, i;
    for (offset = 0;
         remaining > 0;
         offset += 8, remaining -= 8) {
        printf("%016x ", offset);
        if (remaining < 8) {
            for (i = 0; i < remaining; i++)
                printf("%02x ", *(data + offset + i));
        } else {
            for (i = 0; i < 8; i++)
                printf("%02x ", *(data + offset + i));
        }
        printf("\n");
    }
}

void __hex_dump(const uint8_t *data, uint32_t size, uint32_t interval) {
    int32_t remaining = (int32_t) size, offset, i;
    for (offset = 0;
         remaining > 0;
         offset += 8, remaining -= 8) {
        if (offset % interval != 0)
            continue;

        printf("%016x ", offset);
        if (remaining < 8) {
            for (i = 0; i < remaining; i++)
                printf("%02x ", *(data + offset + i));
        } else {
            for (i = 0; i < 8; i++)
                printf("%02x ", *(data + offset + i));
        }
        printf("\n");
    }
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

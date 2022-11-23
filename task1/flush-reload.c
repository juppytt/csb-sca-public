#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sched.h>

#include "utils.h"

#define BIN_WIDTH 10
#define NUM_BINS 80
#define NUM_REPEAT 32 * 1024

static uint8_t oracle[256 * 64];
static uint64_t only_load[NUM_BINS];
static uint64_t flush_and_reload[NUM_BINS];

int main(int argc, char *argv[])
{
    int i, j;
    uint64_t res;

    for (j = 0; j < NUM_REPEAT; ++j) {
        /*********** TODO: flush+reload ************/
        /*********** TODO: flush+reload ************/
        sched_yield();
    }
    
    for (j = 0; j < NUM_REPEAT; ++j) {
        /*********** TODO: only reload *************/
        /*********** TODO: only reload *************/
        sched_yield();
    }

    // Don't edit this! This is the column header
    printf("cycles,load,flush+reload\n");

    for (i = 0; i < NUM_BINS; ++i) {
        printf("%d,%lu,%lu\n", BIN_WIDTH*i, only_load[i], flush_and_reload[i]);
    }

    return 0;
}

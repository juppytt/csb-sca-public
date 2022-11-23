#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sched.h>

#include "utils.h"
#include "oracle.h"

#define BIN_WIDTH 5
#define NUM_BINS 200
#define NUM_REPEAT 2 * 1024

// kernel module will access this memory. Do not edit this
static uint8_t oracle[256 * 64];

// This informs the kernel module about the oracle. Do not edit this
static struct oracle_info oracle_info = {
    .addr = (unsigned long) oracle,
    .size = 256 * 64
};

uint32_t flush_reload(int fd, int* index, uint8_t* addr) {
    int i;
    uint32_t score;
    uint64_t res;
    uint64_t time_elapsed[NUM_BINS] = { 0 };

    //===-------- (optional) TODO: Define some useful variables --------===//
    //===-------- (optional) TODO: Define some useful variables --------===//

    for (i = 0; i < NUM_REPEAT; i++) {
        //===-------- TODO: flush+relaod --------===//
        //===-------- TODO: flush+relaod --------===//
        usleep(5);
        // sched_yield();
    }

    //===-------- TODO: calculate score, e.g. 3rd quartile --------===//
    //===-------- TODO: calculate score, e.g. 3rd quartile --------===//

    return score;
}

static uint32_t score[256];

int main(int argc, char *argv[])
{
    int fd, ret = 0, i, j = 15 /* modify this! */;
    int c;
    uint64_t res;

    // Do not edit this.
    fd = open("/dev/mystery", O_RDWR);
    if (fd < 0)
        handle_error("[-] Cannot open the device");

    setup_oracle(fd, &oracle_info);

    printf("[+] %p: oracle_info{ addr: 0x%lx, size: 0x%lx}\n",
           &oracle_info, oracle_info.addr, oracle_info.size);

    //===-------- TODO: flush+relaod --------===//
    //===-------- TODO: flush+relaod --------===//

    // DO not edit this
    close(fd);
}


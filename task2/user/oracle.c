#include "oracle.h"

int setup_oracle(int fd, struct oracle_info* oracle_info) {
    return ioctl(fd, MYSTERY_IOCTL_CMD_SETUP_ORACLE, oracle_info);
}

int run(int fd, int *secret_inex) {
    return ioctl(fd, MYSTERY_IOCTL_CMD_RUN, secret_inex);
}

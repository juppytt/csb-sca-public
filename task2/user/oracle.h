#include <unistd.h>
#include <sys/ioctl.h>

#define MYSTERY_IOCTL_MAGIC_NUMBER 's'
#define MYSTERY_IOCTL_CMD_SETUP_ORACLE \
    _IOR(MYSTERY_IOCTL_MAGIC_NUMBER, 0x1, struct oracle_info)
#define MYSTERY_IOCTL_CMD_RUN \
    _IOR(MYSTERY_IOCTL_MAGIC_NUMBER, 0x2, int)
#define MYSTERY_IOCTL_CMD_GUESS \
    _IOWR(MYSTERY_IOCTL_MAGIC_NUMBER, 0x4, struct guess)

struct oracle_info {
    long addr;
    size_t size;
};

// currently not being used
struct guess {
    char value[16];
    char log[128];
};

/**
 * setup_oracle() - setup oracle ioctl command
 * @fd: file descriptor of miscdevice
 * @oracle_info: oracle_info containing userland oracle address.
 */
int setup_oracle(int fd, struct oracle_info* oracle_info);

/**
 * run() - run ioctl command with secret index
 * @fd: file descriptor of miscdevice
 * @secret_index: kernel secret index
 */
int run(int fd, int *secret_index);

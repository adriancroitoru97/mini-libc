#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret;

    do {
        ret = syscall(__NR_nanosleep, req, rem);
    } while (ret == -1 && errno == EINTR);

    return ret;
}

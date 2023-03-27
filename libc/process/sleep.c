#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req = { .tv_sec = seconds };
    struct timespec rem = { 0 };

    while (nanosleep(&req, &rem) == -1 && rem.tv_sec > 0) {
        req = rem;
        rem.tv_sec = rem.tv_nsec = 0;
    }

    return 0;
}

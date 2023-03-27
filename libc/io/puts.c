// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <unistd.h>

int puts(const char *s) {
    int count = 0;

    while (*s != '\0') {
        write(1, s, 1);
        s++;
        count++;
    }

    write(1, "\n", 1);
    count++;

    return count;
}

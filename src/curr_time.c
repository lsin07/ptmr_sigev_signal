#include <time.h>
#include "curr_time.h"

char *currTime(const char *format) {
    static char buf[64];
    time_t t;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);
    if (tm == NULL || strftime(buf, sizeof(buf), format, tm) == 0)
        return NULL;

    return buf;
}
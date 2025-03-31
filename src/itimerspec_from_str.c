#define _POSIX_C_SOURCE 199309
#include <string.h>
#include <stdlib.h>
#include "itimerspec_from_str.h"    /* Declares function defined here */
#include "err_hdr.h"

void itimerspecFromStr(char *str, struct itimerspec *tsp)
{
    char *cptr, *sptr;
    char *strbuf = malloc(strlen(str) + 1);
    if (strbuf == NULL) {
        errExit("malloc");
    }
    strcpy(strbuf, str);

    cptr = strchr(strbuf, ':');
    if (cptr != NULL)
        *cptr = '\0';

    sptr = strchr(strbuf, '/');
    if (sptr != NULL)
        *sptr = '\0';

    tsp->it_value.tv_sec = atoi(strbuf);
    tsp->it_value.tv_nsec = (sptr != NULL) ? atoi(sptr + 1) : 0;

    if (cptr == NULL) {
        tsp->it_interval.tv_sec = 0;
        tsp->it_interval.tv_nsec = 0;
    } else {
        sptr = strchr(cptr + 1, '/');
        if (sptr != NULL)
            *sptr = '\0';

        tsp->it_interval.tv_sec = atoi(cptr + 1);
        tsp->it_interval.tv_nsec = (sptr != NULL) ? atoi(sptr + 1) : 0;
    }

    free(strbuf);
}

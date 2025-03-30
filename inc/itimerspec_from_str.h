#ifndef _ITIMERSPEC_FROM_STR_H
#define _ITIMERSPEC_FROM_STR_H

#include <time.h>

/* Convert a string of the following form to an itimerspec structure:
   "value.sec[/value.nanosec][:interval.sec[/interval.nanosec]]".
   Optional components that are omitted cause 0 to be assigned to the
   corresponding structure fields. */
void itimerspecFromStr(char *str, struct itimerspec *tsp);

#endif
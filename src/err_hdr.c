#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Error handler */
void errExit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void usageErr(const char *msg, const char* cmd) {
    printf("Usage: ");
    printf(msg, cmd);
    exit(EXIT_FAILURE);
}
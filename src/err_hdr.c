#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void errExit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void usageErr(const char *msg, const char* cmd) {
    char usage[] = "Usage: ";
    char *buf = malloc(strlen(msg) + strlen(usage) + 1);
    strcpy(buf, usage);
    strcat(buf, msg);
    fprintf(stderr, buf, cmd);
    free(buf);
    exit(EXIT_FAILURE);
}
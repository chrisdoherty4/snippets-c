#include <stdio.h>
#include <errno.h>
#include <string.h>

int main (int argc, char *argv[])
{
    FILE *fh = NULL;
    char read_character;
    int lines = 0;

    if (argc != 2) {
        fprintf(stderr, "Error: expecting 2 arguments");
        return 1;
    }

    fh = fopen(argv[1], "r");

    if (fh == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }

    while ((read_character = getc(fh)) != EOF) {
        if (read_character == '\n') {
            ++lines;
        }
    }

    printf("Found %d lines\n", lines);

    return 0;
}

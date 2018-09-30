#include <stdio.h>

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
        fprintf(stderr, "Error: failed to open file\n");
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

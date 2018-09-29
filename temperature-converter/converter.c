#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

float cel2far(float c);
float far2cel(float f);

int main (int argc, char * argv[])
{
    float f;
    int i;
    char *program = NULL, *slash = NULL;
    float (*converter)(float);

    if (argc < 2) {
        fprintf(stderr, "Error: expected at least 2 arguments\n");
        return 1;
    };

    // Extract the program name from the path
    program = argv[0];
    if ((slash = strrchr(argv[0], '/')) != NULL) {
        program = slash + 1;
    }

    if (strcmp(program, "cel2far") == 0){
        converter = cel2far;
    } else if (strcmp(program, "far2cel") == 0) {
        converter = far2cel;
    } else {
        fprintf(stderr, "Error: unexpected program name.\n");
        exit(0);
    }

    for (i = 1; i < argc; i++) {
        f = strtof(argv[i], NULL);

        if (errno == ERANGE) {
            fprintf(stderr, "Error: invalid floating point number %s\n", argv[i]);
            errno = 0;
            continue;
        }

        printf("%-12s = %.2f\n", argv[i], converter(f));
    }

    return 0;
}

float cel2far(float c) {
    return c * 9 / 5 + 32;
}

float far2cel(float f) {
    return (f - 32) * 5 / 9;
}

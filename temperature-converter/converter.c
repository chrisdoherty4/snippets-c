#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

float cel2far(float c);
float far2cel(float f);

float (*converter)(float);

int main (int argc, char * argv[])
{
    float f;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Error: expected at least 2 arguments\n");
        return 1;
    }

    if (argv[0] = "cel2far"){
        converter = cel2far;
    } else if (argv[0] = "far2cel") {
        converter = far2cel;
    }

    for (i = 1; i < argc; i++) {
        f = strtof(argv[i], NULL);

        if (errno == ERANGE) {
            fprintf(stderr, "Error: invalid floating point number %s", argv[i]);
            return 1;
        }

        printf("%-12s = %.0f", argv[i], f);
    }

    return 0;
}

float cel2far(float c) {
    return 0.0
}

float far2cel(float f) {
    return 0.0;
}

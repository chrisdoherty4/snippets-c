#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Error: expeting argument 1 to be a test string");
        return 1;
    }

    char *test_string = argv[1];
    int string_len = strlen(test_string) + 1, i = 0;
    char buffer[string_len];
    bool found_space = false;

    // Manually initialise memory of dynamically defined buffer.
    memset(buffer, 0, string_len);

    printf("Original: %s\n", test_string);

    while (*test_string != '\0') {
        if (*test_string == ' ' && found_space == true) {
            test_string++;
            continue;
        } else if (*test_string == ' ') {
            found_space = true;
        } else {
            found_space = false;
        }

        buffer[i++] = *test_string;
        test_string++;
    }
    buffer[i] = '\0';

    printf("Triaged: %s\n", buffer);

    return 0;
}

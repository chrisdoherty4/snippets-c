#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DOUBLE_SPACE "  "

int main(int argc, char *argv[])
{
    char *test_string = "This is  a test    string      with some   added spaces";

    int string_len = strlen(test_string) + 1, i = 0;
    char buffer[string_len];
    bool found_space = false;

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
}

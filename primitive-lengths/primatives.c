#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char *format = "%-12s%-6d%-6d\n";

    printf("%-12s%-6s%-6s\n", "Type", "Bytes", "Bits");
    printf(format, "char", sizeof(char), sizeof(char) * 8);
    printf(format, "short", sizeof(short), sizeof(short) * 8);
    printf(format, "int", sizeof(int), sizeof(int) * 8);
    printf(format, "long", sizeof(long), sizeof(long) * 8);
    printf(format, "long long", sizeof(long long), sizeof(long long) * 8);
    printf(format, "float", sizeof(float), sizeof(float) * 8);
    printf(format, "double", sizeof(double), sizeof(double) * 8);
    printf(format, "long double", sizeof(long double), sizeof(long double) * 8);

    return 0;
}

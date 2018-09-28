#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) 
{
    printf("%-12s%-12s\n", "Type", "Length");
    printf("%-12s%-12d\n", "char", sizeof(char));
    printf("%-12s%-12d\n", "short", sizeof(short));
    printf("%-12s%-12d\n", "int", sizeof(int));
    printf("%-12s%-12d\n", "long", sizeof(long));
    printf("%-12s%-12d\n", "long long", sizeof(long long));
   
    return 0;
}

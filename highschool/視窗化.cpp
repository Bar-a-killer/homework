#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
int main()
{
    const char* filename = "¦a¹Ï(BETA).txt";
    FILE* input_file = fopen(filename, "r");
    printf("%s",input_file);
    return 0;
}

#include <stdio.h>
#include <string.h>
int main() {
    char arr[257];
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
        fgets(arr, 257, stdin);
        arr[strcspn(arr, "\n")] = '\0';
        int dotpos = -1;
        int lastslash = -1;
        for(int i = 0; arr[i] != '\0'; i++) {
            if(arr[i] == '.') {
                dotpos = i;
            }
            else if(arr[i] == '\\' || arr[i] == ':') {
                lastslash = i;
            }
        }
        char frontpart[257] = "";
        char backpart[257] = "";
        char middlepart[257];
        fgets(middlepart, 257, stdin);
        middlepart[strcspn(middlepart, "\n")] = '\0';
        int k = 0;
        if(lastslash != -1) {
            k += 1;
            strncpy(frontpart, arr, lastslash + 1);
            frontpart[lastslash + 1] = '\0';
        }
        if(dotpos != -1 && dotpos > lastslash) {
            k += 2;
            strcpy(backpart, arr + dotpos);
        }
        if(k == 3)
            printf("%s%s%s\n", frontpart, middlepart, backpart);
        else if(k == 1)
            printf("%s%s\n", frontpart, middlepart);
        else if(k == 2)
            printf("%s%s\n", middlepart, backpart);
        else
            printf("%s\n", middlepart);
    }
}
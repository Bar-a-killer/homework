#include <stdio.h>
int main() {
    char T[100],t[10];
    int kmp[10] = {0};
    scanf("%s%s",T,t);
    int i=1,j= -1;
    kmp[0] = -1;
    while(t[i] != '\0') {
        if(t[i] == t[j+1]) {
            kmp[i] = kmp[i-1] + 1;
            i++,j++;
        } else {
            while(j >= 0 && t[i] != t[j+1]) {
                j = kmp[j];
            }
            kmp[i] = kmp[j];
            if(t[i] == t[j + 1]) {
                kmp[i]++;
            }
            i++;
        }
    }
    i = -1;
    for(j=0;j<100 && T[j] != '\0';j++) {
        if(T[j] == t[i+1]) {
            i++;
        } else {
            while(i >= 0 && T[j] != t[i+1]) {
                i = kmp[i];
            }
            if(T[j] == t[i + 1]) {
                i++;
            }
        }
        if(t[i+1] == '\0') {
            printf("%d\n",1);
            return 0;
        }
    }
    printf("%d\n",-1);
}
#include <stdio.h>
#include <string.h>

#define MAX 50000
int solve(int a[], int n) {
    int max_len = 2;
    int max,min,i,j,k;
    for(i = 0; i < n; ++i) { 
        for(j = i+1; j < n; ++j) { 
            if (a[i]>a[j]) { 
                max = a[i]; min = a[j]; 
            } else { 
                max = a[j]; min = a[i]; 
            } 
            for(k=i+1; k < j; ++k) { 
                if (a[k]>max||a[k]<min) { 
                    break; 
                } 
            } 
            if (k== j) { 
                int len; 
                // the subsequence between i and j is a bounded subsequence. 
                // the length of this bounded subseqnece is j-i+1 
                len = j-i+1; 
                if (len > max_len) { 
                    max_len = len; 
                } 
            } 
        }
    }
    return max_len;
}
int main() {
    
    while (1) {
        int a[MAX];
        int n = 0;
        char c;
        if(scanf("%d%c", &a[n++], &c) == EOF) return 0;
        while (scanf("%d%c", &a[n++], &c) == 2) {
            if (c == '\n') break; 
        }
        printf("%d\n", solve(a, n));
    }
}
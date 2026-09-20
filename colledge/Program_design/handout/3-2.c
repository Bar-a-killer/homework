#include <stdio.h>
#include <math.h>
int main() {
    int n;
    char c[2] = {'X','A'};
    scanf("%d",&n);
    n += n-1;
    for(int i=1;i<=n;i++) {
        int j = 1;
        for(j=1;j<=i;j++) {
            printf("%c",c[i%2]);
        }
        while(j<=n) {
            printf("%c",c[j%2]);
            j++;
        }
        printf("\n");
    }
    return 0;
}

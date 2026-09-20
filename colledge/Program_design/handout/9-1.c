#include <stdio.h>
#include <stdlib.h>
int main() {
    
    int M;
    scanf("%d",&M);
    while(M--) {
        int left = 0;
        int m;
        scanf("%d",&m);
        int k = m+2;
        int a[100][100];
        char tmp;
        for(int i = 0; i <= m+1 ; i++) {
            for(int j = 0; j <= m+1; j++) {
                if(i == 0 || j == 0 || i == m+1 || j == m+1) {
                    a[i][j] = 1;
                    continue;
                }
                scanf("%c",&a[i][j]);
                a[i][j] -= '0';
                if(a[i][j] == 1) {
                    left++;
                }
            }
            if(i != m+1)
                scanf("%c",&tmp);
        }
        for(int x = 1; x <= m ; x++) {
            for(int y = 1; y <= m; y++) {
                if(a[y][x] == 1 && 
                (a[y-1][x-1] == 0 || a[y-1][x] == 0 || a[y-1][x+1] == 0||
                a[y][x-1] == 0||a[y][x+1] == 0||
                a[y+1][x-1] == 0 || a[y+1][x] == 0 || a[y+1][x+1] == 0)) {
                    left--;
                }
            }
        }
        printf("%d\n",left);
    }
    return 0;
}
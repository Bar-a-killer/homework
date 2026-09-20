#include <stdio.h>

int main() {
    unsigned long long int dp[50][50] = {0};
    dp[0][0] = 1;
    for(int red = 0;red <= 20;red++) {
        for(int green = 0;green <= 20;green++) {
            unsigned long long int total = dp[green][red];
            dp[green][red+1] += total;
            dp[green][red+2] += total;
            dp[green][red+3] += total;

            dp[green+1][red] += total;
            dp[green+2][red] += total;
            dp[green+3][red] += total;

            dp[green+1][red+1] += total;
            dp[green+2][red+1] += total;
            dp[green+1][red+2] += total;
        }
    }
    int g,r;
    while(scanf("%d%d",&r,&g) != EOF) {
        unsigned long long int ans = 0;
        if(g>=3) ans = dp[g-1][r]+dp[g-2][r]+dp[g-3][r];
        else if(g == 2) ans =  dp[g-1][r]+dp[g-2][r];
        else if(g == 1) ans = dp[g-1][r];

        //
        printf("%llu\n",ans);
        //printf("%lld\n",ans);
    }
}
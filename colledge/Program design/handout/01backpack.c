#include <stdio.h>
int main() {
    int n, w;
    scanf("%d %d", &n, &w);
    int weights[10000];
    int values[10000];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &values[i], &weights[i]);
    }
    int dp[10001] = {0};
    
    for (int i = 0; i < n; i++) {
        for(int k = w; k >= weights[i]; k--) {
            if (dp[k - weights[i]] + values[i] > dp[k]) {
                dp[k] = dp[k - weights[i]] + values[i];
            }
        }
    }
    printf("Maximum total value:%d\n", dp[w]);
    return 0;
}
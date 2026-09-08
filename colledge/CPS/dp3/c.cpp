#include<bits/stdc++.h>
using namespace std;
#define long long

int dp[501][501] = {0};
signed main() {
    int n;
    cin >> n;
    string s;cin >> s;
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++)
        for (int l = 0;l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = 1 + dp[l+1][r];
            for (int k = l+1; k <= r; k++)
                if (s[l] == s[k])
                    dp[l][r] = min(dp[l][r], dp[l+1][k] + dp[k+1][r]);
        }
    cout << dp[0][n-1];
}
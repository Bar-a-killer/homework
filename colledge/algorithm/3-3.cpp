#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18
int mapp[1003][1003];
int dp[1003][1003];
signed main() {
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> mapp[i][j];
            dp[i][j] = INF;
            if(j == 0) dp[i][j] = mapp[i][j];
        }
    }
    for(int j = 0;j < m-1;j++) {
        for(int i = 0;i < n;i++) {
            int nj = j+1;
            int ni[3] = {(i-1+n)%n,i,(i+1)%n};
            for(int nni:ni) {
                dp[nni][nj] = min(dp[i][j]+mapp[nni][nj],dp[nni][nj]);
            }
        }
    }
    int ans = INF;
    for(int i = 0;i < n;i++) {
        ans = min(ans,dp[i][m-1]);
    }
    if(ans > k) cout << "RE: START :<" << endl;
    else cout << ans << endl;
}
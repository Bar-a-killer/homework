#include <bits/stdc++.h> 
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
    int n,a,b,k;
    cin >> n;
    cin >> a >> b;
    cin >> k;
    int dp[2000][n+1];
    for(int j=0;j<=n;j++) {
        if((j-a)*(j-a) < (b-a)*(b-a) && a!=j)
            dp[0][j] = 1;
        else 
            dp[0][j] = 0;
    }
    for(int i=1;i<k;i++) {
        for(int j=1;j<=n;j++) {
            dp[i][j]=0;
            for(int l=1;l<=n;l++) {
                if((j-l)*(j-l) < (b-l)*(b-l) && j!=l) {
                     dp[i][j] += dp[i-1][l];
                     dp[i][j] %= 1000000007;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        ans+=dp[k-1][i]; 
        ans %= 1000000007;
    }
    cout << ans << endl;
}
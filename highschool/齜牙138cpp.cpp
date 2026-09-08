#include <bits/stdc++.h>
using namespace std;

int main() {
  int T,n;
  long long ll = 1;
  int dp[50001][2];
  dp[1][0] = 3;
  dp[1][1] = 0;
  dp[2][0] = 9;
  dp[2][1] = 2;
  for(int i=3;i<=50000;i++) {
    dp[i][0] = (ll*dp[i-1][0]+ll*dp[i-1][1])*3%1000007;
    dp[i][1] = (ll*(dp[i-2][0]+dp[i-2][1])*2+ll*dp[i-1][1])%1000007;
  }
  cin >> T;
  while(T--) {
    cin >> n;
    if(n%2) {
      cout << 0 << endl;
      continue;
    }
    cout << (dp[n/2][0]+dp[n/2][1])%1000007 << endl;
  }
}
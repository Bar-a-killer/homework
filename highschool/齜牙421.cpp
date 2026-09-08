#include <bits/stdc++.h>

#define int long long
#define burst ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

signed main(){
  int num[100001], dp[100001][2];
  int T;
  cin >> T;
  while(T--) {
      int N,M;
      cin >> N >> M;
      for(int i = 1; i <= N; i++){
        cin >> num[i];
      }
      dp[0][0] = 0, dp[0][1] = 0;
      for(int i = 1; i <= N; i++){
        if(num[i] * 2 >= M){
           dp[i][1] = max(dp[i-1][0] + (num[i] * 2 >= num[i-1]), dp[i-1][1] + (num[i] * 2 >= num[i-1] * 2));
        }
        else
            dp[i][1] = dp[i-1][1];
        if(num[i] >= M){
          dp[i][0] = max(dp[i-1][0] + (num[i] >= num[i-1]), dp[i-1][1] + (num[i] >= num[i-1] * 2));
        }  
        else
            dp[i][0] = dp[i-1][0];
      }
      cout << max(dp[N][0], dp[N][1]) << endl;
  }
  return 0;
}
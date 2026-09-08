#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> d;
    int pf[500] = {0};

    for(int i = 0;i < n;i++) {
        int tmp; cin >> tmp;
        d.push_back(tmp);
        pf[i+1] = tmp+pf[i];
    }
    int dp[500][500];
    for(int i = 0;i < 500;i++) {
        for(int j = 0;j < 500;j++) {
            dp[i][j] = 1e17;
            if(i == j) dp[i][j] = 0;
        }
    }
    for(int len = 2;len <= n;len++) {
        for(int i = 0;i <= n-len;i++) {
            int j = i+len-1;
            for(int k = i;k < j;k++) {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+\
                                pf[k+1]-pf[i]+pf[j+1]-pf[k+1]);
            }
        }
    }
    // for(int i = 0;i < n;i++) {
    //     for(int j = 0;j < n;j++) {
    //         if(dp[i][j] == 1e17) cout << "@" << "\t";
    //         else 
    //         cout << dp[i][j] << "\t";
    //     } cout << endl;
    // }
    cout << dp[0][n-1] << endl;
}
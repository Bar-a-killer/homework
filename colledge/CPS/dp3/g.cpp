#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) X.begin(),X.end()
const int mod = 1e9+7;
int dp[10001][3][105];
signed main() {
    string K;
    int D;
    cin >> K >> D;
    reverse(all(K));
    dp[K.size()][1][0] = 1;
    for(int i = K.size() - 1; i >= 0; --i){
        auto &prv = dp[i+1];
        auto &cur = dp[i];
        int x = K[i] - '0';
        for(int a = 0; a <= 9; ++a){
            for(int d = 0; d < D;++d){
                cur[0][(d + a) % D] = (cur[0][(d + a) % D] + prv[0][d])%mod;
                if(a < x){
                    cur[0][(d + a) % D] = (cur[0][(d + a) % D]+prv[1][d])%mod;
                }
                if(a == x){
                    cur[1][(d + a) % D] = (cur[1][(d + a) % D]+prv[1][d])%mod;
                }
            }
        }
    }
    cout << (dp[0][1][0] + dp[0][0][0] - 1+ mod)%mod << '\n';
}
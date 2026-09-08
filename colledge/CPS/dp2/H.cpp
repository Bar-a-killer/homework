#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int mod = 1e9+7;
const int mxn = 2e6+5;
i64 fac[mxn];
i64 fpow(i64 a,i64 b){
    i64 ret = 1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ret = ret * a % mod;
    return ret;
}
i64 inv(i64 a){
    return fpow(a,mod-2);
}
i64 comb(i64 n,i64 m){
    return fac[n] * inv(fac[n-m]) % mod * inv(fac[m]) % mod;
}
i64 cnt(int i,int j,auto& A){
    int dx = A[j].first - A[i].first;
    int dy = A[j].second - A[i].second;
    return comb(dx+dy,dy);
}
signed main() {
    fac[0] = 1;
    for(int i = 1; i < mxn;++i) fac[i] = fac[i-1] * i % mod;
    int n,m;
    cin >> n >> m;
    
    vector<pair<int,int>> A;
    A.push_back(pair<int,int>{1,1});
    for(int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        A.push_back({a,b});
    }
    sort(A.begin(),A.end()); 
    A.push_back(pair<int,int>{n,n});
    vector<int> dp(m+5,0);

    for(int i = 1; i <= m+1;++i){
        dp[i] = cnt(0,i,A);
        auto [x,y] = A[i];
        for(int j = 1; j < i;++j){
            auto [xx,yy] = A[j];
            if(xx <= x && yy <= y)
            dp[i] = (dp[i] - cnt(j,i,A) % mod * dp[j] % mod + mod) % mod;
        }
        dp[i] %= mod;
    }
        
    cout << dp[m+1] << endl;
}
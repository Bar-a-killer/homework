#include<bits/stdc++.h>
using namespace std;
#define int long long

#define MXN 2'000'005
#define N 2'000'000
#define ll long long
const int mod = 998244353;
ll fac[MXN], inv[MXN];
ll C(int n,int k){
    if(k < 0 || k > n) return 0;
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}
ll fpow(ll i, int j) {
	ll ret = 1, tmp = i;
	for (; j; j >>= 1, tmp = tmp * tmp % mod)
		if (j & 1) ret = ret * tmp % mod;
	return ret;
}
signed main() {
    int a,b,c;
    cin >> a >> b >> c;
    fac[0] = 1;
    for(int i = 1; i <= N; i++)    fac[i] = fac[i-1] * i % mod;
    inv[N] = fpow(fac[N], mod-2);
    for(int i = N-1; i >=0; i--)   inv[i] = inv[i+1] * (i+1) % mod;
    int ans = 0;
    for(int i=1;i<=min(a,b+1);i++){
        int ways = 1;
        ways = ways * C(b+1, i) % mod;
        ways = ways * C(a-1, i-1) % mod;
        ways = ways * C(b+c-i, c) % mod;

        ans = (ans + ways) % mod;
    }
    cout << ans << endl;
}

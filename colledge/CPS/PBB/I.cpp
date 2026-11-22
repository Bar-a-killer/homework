#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
int fppow(int a,int b) {
    int ans = 0;
    int c = 1;
    while(b) {
        if(b&1) ans = (ans+c)%MOD;
        c = (c*a)%MOD;
        b>>=1;
    }
    return ans;
}
void solve() {
    int a,b;
    cin >> a >> b;
    cout << fppow(a,b) << endl;
}
signed main() {
    int t;cin >> t;
    while(t--) solve();
}
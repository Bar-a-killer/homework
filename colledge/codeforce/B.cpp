#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18
void solve() {
    int n;
    cin >> n;
    int r = -1;
    int l = -1;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> l;
        int t = l-r;
        int g = gcd(l,r);
        if(abs(l-r) == g) {
            ans ++;
        }
        r = l;
    }
    cout << ans << endl;
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
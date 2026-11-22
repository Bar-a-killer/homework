#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;cin >> n;
    int tg;cin >> tg;n--;
    int ans = 0;int dis = 0;
    int tmp;
    while(n--) {
        cin >> tmp;
        if(tmp <= tg) ans += tg-tmp;
        else {
            dis += tmp-tg;
            ans += tmp-tg;
        }
        tg = tmp;
    }
    ans += abs(tg-dis);
    cout << ans << '\n';
}
signed main() {
    int t;cin >> t;
    while(t--) {
        solve();
    }
}

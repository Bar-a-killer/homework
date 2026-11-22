#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,q;cin >> n >> q;
    vector<int> dt(n);
    for(auto &i:dt) cin >> i;
    vector<int> pos(n+1,0);
    while(q--) {
        int l,r;cin >> l >> r;
        pos[l-1] += 1;
        pos[r] -= 1;
    }
    for(int i = 1;i <= n;i++) pos[i] += pos[i-1];
    sort(pos.begin(),pos.end());
    sort(dt.begin(),dt.end());
    int ans = 0;
    for(int i = 0;i < n;i++) ans += dt[i]*pos[i+1];
    cout << ans << endl;
}

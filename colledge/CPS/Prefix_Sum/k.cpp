#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;cin >> n;
    vector<int> dt(n);
    for(auto &i:dt) cin >> i;
    sort(dt.begin(),dt.end());
    int l = 0;int mx = 0;
    for(int i = 1;i < dt.size();i++) {
        while(dt[l]+dt[l+1] <= dt[i]) {
            l++;
        }
        mx = max(mx,i-l+1);
    }
    cout << n-mx << endl;
}
signed main() {
    int t;cin >> t;
    while(t--) {
        solve();
    }
}

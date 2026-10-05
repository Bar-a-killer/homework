#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;cin >> n;
    vector<int> datas(n);
    for(auto &i:datas) {
        cin >> i;
    }
    sort(datas.begin(),datas.end());
    int pos = datas[(datas.size()+1)/2-1];
    int ans = 0;
    for(auto i : datas) {
        ans += abs(i-pos);
        
    }
    cout << ans << '\n';
}
signed main() {
    int n;
    cin >> n;
    while(n--) {
        solve();
    }
}

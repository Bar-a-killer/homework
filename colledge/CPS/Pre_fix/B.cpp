#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n,x;cin >> n >> x;
    vector<int> dt(n);
    for(auto &i:dt) cin >> i;
    vector<int> pf(n+1);
    pf[0] = 0;
    for(int i = 1;i <= n;i++) pf[i] = pf[i-1LL] + dt[i-1LL];
    map<int,int> hi;
    int ans = 0;
    queue<int> cash;
    cash.push(0);
    for(int i = 1;i <= n;i++) {
        int now = pf[i]%x;
        if(hi.find(now)!=hi.end()) ans += hi[now];
        if(cash.size()>=x) {
            if(hi.find(cash.front())!= hi.end()) hi[cash.front()] ++;
            else hi[cash.front()] = 1;
            cash.pop();
        }
        cash.push(now);
    }
    cout << ans << '\n';
}
signed main() {
    int n;
    cin >> n;
    while(n--) solve();
}

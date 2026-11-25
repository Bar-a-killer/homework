#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
    int n;cin >> n;
    int total = 0;
    vector<int> dt(n);
    for(auto &i:dt) {
        cin >> i;
        total += i;
    }
    set<int> able;
    able.insert(0);
    for(auto i:dt) {
        set<int> nxt = able;
        for (auto j : able) nxt.insert(i + j);
        able = move(nxt);
    }
    int ans = total;
    for(auto  i:able) ans = min(ans,abs(total-2*i));
    cout << ans << endl;
}

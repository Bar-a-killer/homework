#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
    int n,m;cin >> n >> m;
    set<int> able;
    while(n--) {
        set<int> tmp;
        int t;cin >> t;
        t%=m;
        for(auto i:able) {
            tmp.insert((i+t)%m);
        }
        able.insert(t);
        for(auto i:tmp) able.insert(i);
    }
    int ans = 0;
    for(auto i:able) ans = max(ans,i);
    cout << ans << endl;
}

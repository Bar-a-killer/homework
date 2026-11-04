#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,x;cin >> n >> x;
    vector<int> dt(n+1);
    int ans = 0;
    dt[0] = 0;
    for(int i=1;i<=n;i++) {
        cin >> dt[i];
        dt[i] += dt[i-1];
    }
    map<int,int> rrrrr;
    rrrrr[0] = 1;
    for(int i = 1;i <= n;i++) {
        if(rrrrr.find(dt[i]-x) != rrrrr.end())
            ans += rrrrr[dt[i]-x];
        if(rrrrr.find(dt[i]) != rrrrr.end())
            rrrrr[dt[i]]++;
        else rrrrr[dt[i]] = 1;
    }
    cout << ans << endl;    
}

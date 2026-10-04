#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
#define  int long long 

void solve() {
    int n,q;cin >> q >> n;
    vector<int> house(n);
    for(auto& i:house) {
        cin >> i;
    }
    sort(house.begin(),house.end());
    double l = 0,r = house.back();
    while(r - l > 0.01) {
        double mid = (l+r)/2;
        double spot = -1e6;
        int cnt = 0;
        for(auto i:house) {
            if(fabs(spot-i)>mid) {
                cnt++;
                spot = i+mid;
            }
        }
        if(cnt <= q) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(1) <<  l << endl;
}
signed main() {
    int t;cin >> t;
    while(t--) {
        solve();
    }
}

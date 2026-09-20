#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    int targ; cin >> targ;
    vector<int> d(n);
    for(int i = 0;i < n;i++) {
        cin >> d[i];
    }
    sort(d.begin(),d.end());
    for(int i = 0;i < n;i++) {
        int diff = targ + d[i];
        auto it = lower_bound(d.begin(),d.end(),diff);
        if(diff == 0 && it != d.end()) it++; 
        if(it != d.end() && diff == *it) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
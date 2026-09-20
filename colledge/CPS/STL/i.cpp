#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    int targ; cin >> targ;
    vector< pair<int,int> > d(n);
    for(int i = 0;i < n;i++) {
        cin >> d[i].first;
        d[i].second = i+1;
    }
    sort(d.begin(),d.end());
    for(int i = 0;i < n;i++) {
        int diff = targ - d[i].first;
        auto it = lower_bound(d.begin(),d.end(),make_pair(diff,0LL));
        if(diff == d[i].first && it != d.end()) it++; 
        if(it != d.end() && diff == (*it).first) {
            cout << d[i].second << " " << (*it).second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
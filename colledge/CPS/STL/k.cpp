#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    int k;
    cin >> n;
    cin >> k;
    multiset<int> mts_small,mts_big;
    vector<int> d;
    vector<int> dd;
    for(int i = 0;i < n;i++) {
        int tmp;cin >> tmp;
        if(i < k) dd.push_back(tmp);
        d.push_back(tmp);
    }
    sort(dd.begin(),dd.end());
    for(int i = 0;i < k;i++) {
        if(i < (k+1)/2) mts_small.insert(dd[i]);
        else mts_big.insert(dd[i]);
    }
    for(int i = 0;i < n-k;i++) {
        // cout << endl;
        // for(int it:mts_small) cout << it << " ";
        // for(int it:mts_big) cout << it << " ";
        // cout << endl;
        cout << *mts_small.rbegin() << " ";
        if(mts_big.find(d[i]) != mts_big.end()) {
            mts_big.erase(mts_big.find(d[i]));
            mts_big.insert(d[i+k]);
        } else {
            mts_small.erase(mts_small.find(d[i]));
            mts_small.insert(d[i+k]);
        }
        if(!mts_big.empty() && !mts_small.empty() && *mts_big.begin() < *mts_small.rbegin()) {
            int s = *mts_small.rbegin(),b = *mts_big.begin();
            mts_small.erase(prev(mts_small.end()));
            mts_big.erase(mts_big.begin());
            mts_small.insert(b);
            mts_big.insert(s);
        }
    }
    cout << *mts_small.rbegin() << "\n";
}
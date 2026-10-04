#include <algorithm>
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n,q;
    cin >> n >> q;
    vector<int> data(n);
    for(auto& i:data) {
        cin >> i;
    }
    sort(data.begin(),data.end());
    while(q--) {
        int tmp;cin >> tmp;
        cout << data.end() - lower_bound(data.begin(),data.end(),tmp) << '\n';
    }
}

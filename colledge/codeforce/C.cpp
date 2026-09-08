#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> datas(n);
    for(int i = 0;i < n;i++) {
        cin >> datas[i];
    }
    sort(datas.begin(),datas.end());
    int j = 0;
    for(int i = 0;i < n;i++ ) {
        if(datas[i] >= j) {
            j++;
        }
    }
    cout << j << endl;
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
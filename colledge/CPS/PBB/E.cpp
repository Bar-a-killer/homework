#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve() {
    int n;cin >> n;
    int tmp;
    int last;cin >> last;
    cout << 0 << " ";
    for(int i = 1;i < n;i++) {
        cin >> tmp;
        int c = (tmp|last);
        last = c;
        c = (c^tmp);
        cout << c << " ";
    }
    cout << endl;
}
signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}

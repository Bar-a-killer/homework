#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 676767677
void solve() {
    int n;
    cin >> n;
    int tmp = {0};
    int total = 0;
    for(int i = 0;i < n;i++) {
        cin >> tmp;
        if(tmp != 1) {
            total = (total+tmp)%mod;
        }
    }
    if(tmp == 1) {
        total += 1;
    }
    if(total == 0 && n != 0) {
        cout << 1 << endl;
    } else {
        cout << total << endl;
    }
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
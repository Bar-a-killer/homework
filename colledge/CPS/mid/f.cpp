#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n,k;
    cin >> n >> k;
    int base = (1LL << k) - 1;
    int pin1 = 1LL<<(k-1);
    int pin2 = 1LL<<60;
    for(int i = 0;i < k;i++) {
        int nw = base ^ pin1;
        nw ^= pin2;
        while(n < nw) {
            pin2>>=1;
            nw = base ^ pin1;
            nw ^= pin2;
            if(pin2 < pin1) {
                cout << -1 << "\n";
                return;
            }
        }
        pin2 >>= 1;
        pin1 >>= 1;
        base = nw;
    }
    cout << base << "\n";
}
signed main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        solve();
    }
}
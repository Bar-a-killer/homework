#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    while(q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) {
            int v; cin >> v;
            for(int i = l; i <= r; i++) a[i] += v;
        } else if(op == 2) {
            int v; cin >> v;
            for(int i = l; i <= r; i++) a[i] = v;
        } else {
            int s = 0;
            for(int i = l; i <= r; i++) s += a[i];
            cout << s << "\n";
        }
    }
}
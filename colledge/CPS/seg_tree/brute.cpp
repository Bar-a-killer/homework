// brute.cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> cons(m);
    for(auto& [l,r,q] : cons) cin >> l >> r >> q;
    
    // 暴力枚舉每個位置 0~2^30
    // 太慢，改成 per-bit 差分建構
    vector<int> a(n+1, 0);
    for(auto& [l,r,q] : cons) {
        for(int i = l; i <= r; i++) a[i] |= q;
    }
    
    // 驗證
    for(auto& [l,r,q] : cons) {
        int val = (1LL<<30)-1;
        for(int i = l; i <= r; i++) val &= a[i];
        if(val != q) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i==n];
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn = 1e5+5;
int a[maxn];

signed main() {
    int n,m;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if(i) a[i]+=a[i-1];
    }
    cin >> m;
    while(m--) {
        int t;cin >> t;
        int pos = lower_bound(a, a + n, t) - a;
        cout << pos+1 << endl;
    }
}
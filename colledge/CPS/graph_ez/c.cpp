#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,q;cin >> n >> q;
    int edge[100006]={0};
    int scall[100006]={0};
    for(int i = 0;i < n;i++) {
        scall[i+1] = 1;
        edge[i+1] = i+1;
    }
    while(q--) {
        int a,b;cin >> a >> b;
        int roota = a;
        int rootb = b;
        while(edge[roota]!=roota) roota = edge[roota];
        while(edge[rootb]!=rootb) rootb = edge[rootb];
        if(roota == rootb) {
            edge[a] = roota;
            edge[b] = rootb;
        }
        else if(scall[roota] > scall[rootb]) {
            edge[rootb] = roota;
            scall[roota] += scall[rootb];
            edge[a] = roota;
            edge[b] = roota;
        } else {
            edge[roota] = rootb;
            scall[rootb] += scall[roota];
            edge[a] = rootb;
            edge[b] = rootb;
        }
    }
    int ans = 0;
    for(int i = 0;i < n;i++) if(edge[i+1]==i+1) ans++;
    cout << ans-1 << endl;
}

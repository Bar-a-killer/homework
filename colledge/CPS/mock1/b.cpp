#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first 
#define s second
#define MOD 1000000007
#define yuri ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
struct Binary_Indexed_Tree{
    int n;
    vector<int> bit;
    int lowbit(int x) { return x&-x;}
    void init(int _n) {
        n = _n+1;bit = vector<int> (n,0);
    }
    void update(int x,int v) {
        for(;x<n;x+=lowbit(x)) bit[x]= (bit[x]+v)%MOD;
    }
    long long query(int x) {
        long long ret = 0;
        for(;x>0;x-=lowbit(x)) ret=(ret+bit[x])%MOD;
        return ret;
    }
}BIT1,BIT2;
signed main() {
    int n;
    cin >> n;
    vector<int> datas(n);
    for(int i = 0;i < n;i++) {
        cin >> datas[i];
    }
    vector<int> tmp(datas);
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for(int i = 0;i < n;i++) datas[i] = lower_bound(tmp.begin(),tmp.end(),datas[i]) - tmp.begin()+1;
    int m = tmp.size();
    BIT1.init(m+1);
    BIT2.init(m+1);
    BIT1.update(datas[0],1);
    BIT2.update(datas[0],1);
    int ans = 1;
    for(int i = 1;i < n;i++) {
        int v = datas[i];
        int up_i = BIT2.query(v - 1);
        int dn_i = (BIT1.query(m) - BIT1.query(v) + MOD) % MOD;
        ans = (ans + up_i + dn_i + 1) % MOD;
        BIT1.update(datas[i],up_i+1);
        BIT2.update(datas[i],dn_i+1);
    }
    cout << ans << endl;
}
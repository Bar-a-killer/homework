#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yuri ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
struct Binary_Indexed_Tree{
    int n;
    vector<long long> bit;
    int lowbit(int x){
        return x&-x;
    }
    void init(int _n){
        n = _n+1;
        bit = vector<long long>(n,0);
    }
    void update(int x,int v){
        for(; x<n; x+=lowbit(x)){
            bit[x] += v;
        }
    }
    long long query(int x){
        long long ret = 0;
        for(; x>0; x-=lowbit(x)){
            ret += bit[x];
        }
        return ret;
    }
}BIT;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> tmp = a;
    vector<pair<int, int>> pre(n);
    for(int i=0; i<n; i++){
        pre[i] = {a[i], i};
    }
    sort(pre.begin(), pre.end());
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i=0; i<n; i++){
        a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin() + 1;
    }
    BIT.init(n);
    int ans = 0;
    for(int i = n-1; i>=0; i--){
        
    }
    cout << ans << "\n";
}
signed main() {
    yuri;
    solve();
}
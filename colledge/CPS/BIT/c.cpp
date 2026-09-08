#include<bits/stdc++.h>
using namespace std;
#define int long long

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
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [](pair<int,int> &x, pair<int,int> &y){
        if(x.first == y.first) return x.second > y.second;
        return x.first > y.first;
    });

    int tmp[n];
    for(int i = 0; i < n; i++) tmp[i] = a[i].second;
    sort(tmp, tmp + n);
    int len = unique(tmp, tmp + n) - tmp;
    for(int i = 0; i < n; i++) a[i].second = lower_bound(tmp, tmp + n, a[i].second) - tmp + 1;

    BIT.init(n);
    int ans = 0;
    for(int i = n-1; i >= 0;){
        int j = i;
        BIT.update(a[i].second, 1);
        while(i > 0 && a[i].first == a[i-1].first) {
            BIT.update(a[i].second, 1);
            i--;
        }
        while(j >= i) {
            int score = abs(n - 2*BIT.query(a[j].second));
            if(score >= k) {
                ans++;
            }
            //cout << a[j].first << " " << a[j].second << " " << score << " " << BIT.query(a[j].second) << "\n";
            j--;
        }
    }
    cout << ans << "\n";
}
signed main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
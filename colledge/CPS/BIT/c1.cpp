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
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    
    int tmp[n];
    for(int i = 0; i < n; i++) tmp[i] = a[i].second;
    sort(tmp, tmp + n);
    int len = unique(tmp, tmp + n) - (tmp);
    for(int i = 0; i < n; i++) a[i].second = lower_bound(tmp, tmp + len, a[i].second) - (tmp) + 1;
    
    sort(a.begin(), a.end());
    //for(int i = 0; i < n; i++) cout << a[i].first << " " << a[i].second << "\n";
    BIT.init(n);
    int ans = 0;
    for(int i = 0; i < n; ){
        int j = i;
        int count = 0;
        while(j < n && a[j].first == a[i].first && a[j].second == a[i].second) {
            count++;
            j++;
        }
        BIT.update(a[i].second, count-1);
        int score = n - 2*BIT.query(a[i].second) - 1;
        BIT.update(a[i].second, 1);
        //cout << score << "\n";
        score = score>0?score:-score;
        if(score >= k) {
            ans+=count;
        }
            //cout << a[j].first << " " << a[j].second << " " << score << " " << BIT.query(a[j].second) << "\n";
        i = j;
    }
    cout << ans << "\n";
}
signed main() {
    yuri;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
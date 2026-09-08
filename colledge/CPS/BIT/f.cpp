#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yuri ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX (1e9+1)
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
struct question{
    int begin,end;
    int k;
    int index;
};

void solve() {
    int n,k;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] = MAX-a[i];
    }
    vector<question> questions(200000);
    vector<question> q_sort_begin(200000);
    vector<question> q_sort_end(200000);
    int q;
    cin >> q;
    vector<int> ans(200000);
    for(int i=0; i<q; i++){
        cin >> questions[i].begin >> questions[i].end >> questions[i].k;
        questions[i].k = MAX-questions[i].k;
    }
    
    BIT.init(20000);
    for(int i=0, j=0, k=0; i<q; i++){
        while(j<q && q_sort_begin[j].begin == i){
            ans[q_sort_begin[j].index] -= BIT.query(q_sort_begin[j].k);
            j++;
        }
        while(k<q && q_sort_end[k].end == i){
            ans[q_sort_end[k].index] += BIT.query(q_sort_end[k].k);
            k++;
        }
        BIT.update(a[i], 1);
    }
    for(int i=0; i<q; i++) {
        cout << ans[i] << "\n";
    }
}
signed main() {
    yuri;
    solve();
}
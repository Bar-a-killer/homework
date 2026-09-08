#include<bits/stdc++.h>
using namespace std;
#define int long long
#define cl(X) (X<<1)+1
#define cr(X) (X<<1)+2
#define INF (1LL<<63)-1
class seg_T{
    public:
    int n;
    vector<int> seg_tree;
    vector<int> datas;
    seg_T(int a) {
        seg_tree.resize(a*4+5);
        n = a;
        for(int i = 0;i<n*4;i++) {
            seg_tree[i] = 0;
        }
        datas.resize(n);
    }
    void input_datas() {
        for(int i = 0;i < n;i++) {
            datas[i] = 0;
        }
    }
    void pull(int id) {
        seg_tree[id] = seg_tree[cl(id)]&seg_tree[cr(id)]; 
    }
    void build(int id,int l,int r) {
        if(l==r) {
            seg_tree[id] = datas[l];
            return;
        }
        int mid = (l+r)>>1;
        build(cl(id),l,mid);
        build(cr(id),mid+1,r);
        pull(id);
    }
    void build() {
        build(0,0,n-1);
    }
    int take(int l,int r,int sl,int sr,int id) {
        if(sl<=l&&r<=sr){
            return seg_tree[id];
        }
        int mid = (l+r) >> 1;
        int res = INF;
        if(sl <= mid) {
            res &= take(l,mid,sl,sr,cl(id));
        }
        if(sr > mid) {
            res &= take(mid+1,r,sl,sr,cr(id));
        }
        return res;
    }
    int take(int l,int r) {
        return take(0,n-1,l,r,0);
    }
    void output() {
        for(int i = 0;i < n;i++) {
            cout << datas[i] << " ";
        }
        cout << endl;
    }
    void range_or(int l,int r,int q) {
        for(int i = l;i<=r;i++) {
            datas[i] |= q;
        }
    }
};
signed main() {
    int n,q;
    cin >> n >> q;
    seg_T t(n);
    t.input_datas();
    vector<tuple<int,int,int>> cons(q);
    for(auto& [l,r,q] : cons) {
        cin >> l >> r >> q;
        t.range_or(l-1, r-1, q);
    }
    t.build();

    for(auto& [l,r,q] : cons) {
        if(t.take(l-1,r-1) != q) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    t.output();
}
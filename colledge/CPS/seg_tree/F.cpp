#include<bits/stdc++.h>
using namespace std;
#define int long long
#define cl(X) (X<<1)+1
#define cr(X) (X<<1)+2
#define INF 1e18
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
            datas[i] = 1;
        }
    }
    void pull(int id) {
        seg_tree[id] = seg_tree[cl(id)]+seg_tree[cr(id)]; 
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
    int take(int l,int r,int id,int nn) {
        if(l == r) {
            update(l,0);
            return l;
        }
        int mid = (l+r) >> 1;
        if(seg_tree[cl(id)] < nn) {
            nn-=seg_tree[cl(id)];
            return take(mid+1,r,cr(id),nn);
        } else {
            return take(l,mid,cl(id),nn);
        }
    }
    int take(int nn) {
        return take(0,n-1,0,nn);
    }
    void update(int l,int r,int pos,int id) {
        if(l == r) {
            seg_tree[id] = datas[pos];
            return;
        }
        int mid = (l+r) >> 1;
        if(pos <= mid) {
            update(l,mid,pos,cl(id));
        }
        if(pos > mid) {
            update(mid+1,r,pos,cr(id));
        }
        pull(id);
    }
    void update(int pos,int val) {
        datas[pos] = val;
        update(0,n-1,pos,0);
    }
    void throwout() {
        for(int i = 0;i<n*2;i++) {
            cout << seg_tree[i] << " ";
        }
        cout << endl;
    }
};
signed main() {
    int n;
    cin >> n;
    seg_T t(n);
    t.input_datas();
    t.build();
    int lists[n+1];
    for(int i = 1;i <= n;i++) {
        cin >> lists[i];
    }
    //t.throwout();
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin >> tmp;
        cout << lists[t.take(tmp)+1] << " ";
        //t.throwout();
    }
}
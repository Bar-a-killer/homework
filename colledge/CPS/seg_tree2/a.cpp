
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define cl(X) (X<<1)
#define cr(X) ((X<<1)+1)
#define INF 1e18
class seg_T{
    public:
    int n;
    vector<int> seg_tree;
    vector<int> datas;
    vector<int> tag;
    seg_T(int a) {
        seg_tree = vector<int>(a * 4+5, 0);
        tag = vector<int>(a * 4+5, 0);
        n = a;
        datas.resize(n+1,0);
    }
    void input_datas() {
        for(int i = 0;i < n;i++) {
            cin >> datas[i];
        }
    }
    void push(int id,int l,int r) {
        if(tag[id]) {
            seg_tree[id] += (r-l+1)*tag[id];
            if(l != r) {
                tag[cl(id)] += tag[id];
                tag[cr(id)] += tag[id];
            }
            tag[id] = 0;
        }
    }
    void pull(int id,int l,int r) {
        int mid = (l+r) >> 1;
        push(cl(id),l,mid);
        push(cr(id),mid+1,r);
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
        pull(id,l,r);
    }
    void build() {
        build(1,1,n);
    }
    int query(int l,int r,int sl,int sr,int id) {
        push(id,l,r);
        if(sl<=l&&r<=sr){
            return seg_tree[id];
        }
        int mid = (l+r) >> 1;
        int res = 0;
        if(sl <= mid) {
            res += query(l,mid,sl,sr,cl(id));
        }
        if(sr > mid) {
            res += query(mid+1,r,sl,sr,cr(id));
        }
        return res;
    }
    int query(int l,int r) {
        return query(1,n,l,r,1);
    }
    void update(int l,int r,int id,int ql,int qr,int v) {
        push(id,l,r);
        if(ql<=l&&r<=qr) {
            tag[id] += v;
            return;
        }
        int mid = (l+r) >> 1;
        if(ql <= mid) {
            update(l,mid,cl(id),ql,qr,v);
        }
        if(qr > mid) {
            update(mid+1,r,cr(id),ql,qr,v);
        }
        pull(id,l,r);
    }
    void update(int val,int l,int r) {
        update(1,n,1,l,r,val);
    }
    void throwout() {
        for(int i = 0;i<n*2;i++) {
            cout << seg_tree[i] << " ";
        }
        cout << endl;
        for(int i = 0;i<n*2;i++) {
            cout << tag[i] << " ";
        }
        cout << endl << endl;
    }
};
void solve() {
    int n,q;
    cin >> n >> q;
    seg_T t(n);
    for(int i = 0;i<q;i++) {
        int op=0;
        cin >> op;
        int l,r;
        cin >> l >> r;
        if(op == 1) {
            cout << t.query(l,r) << endl;
        } else {
            int val;
            cin >> val;
            t.update(val,l,r);
        }
        //t.throwout();
    }
}
signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}
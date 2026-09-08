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
    vector<int> tag_add;
    vector<int> tag_set;
    seg_T(int a) {
        seg_tree = vector<int>(a * 4+5, 0);
        tag_add = vector<int>(a * 4+5, 0);
        tag_set = vector<int>(a * 4+5, -1);
        n = a;
        datas.resize(n+1,0);
    }
    void input_datas() {
        for(int i = 1;i <= n;i++) {
            cin >> datas[i];
        }
    }
    void push(int id,int l,int r) {
        if(tag_add[id] && tag_set[id] != -1) {
            seg_tree[id] = (r-l+1)*tag_set[id]\
                            + (r-l+1)*tag_add[id];
            tag_set[id] += tag_add[id];
            if(l != r) {
                tag_set[cl(id)] = tag_set[id];
                tag_set[cr(id)] = tag_set[id];
                tag_add[cl(id)] = 0;
                tag_add[cr(id)] = 0;
            }
            tag_set[id] = -1;
            tag_add[id] = 0;
        } else if(tag_add[id]) {
            seg_tree[id] += (r-l+1)*tag_add[id];
            if(l != r) {
                tag_add[cl(id)] += tag_add[id];
                tag_add[cr(id)] += tag_add[id];
            }
            tag_add[id] = 0;
        } else if(tag_set[id] != -1) {
            seg_tree[id] = (r-l+1)*tag_set[id];
            if(l != r) {
                tag_set[cl(id)] = tag_set[id];
                tag_set[cr(id)] = tag_set[id];
                tag_add[cl(id)] = 0;
                tag_add[cr(id)] = 0;
            }
            tag_set[id] = -1;
            tag_add[id] = 0;
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
    void update_set(int l,int r,int id,int ql,int qr,int v) {
        push(id,l,r);
        if(ql<=l&&r<=qr) {
            seg_tree[id] = (r - l + 1) * v;
            tag_set[id] = v;
            tag_add[id] = 0;
            return;
        }
        int mid = (l+r) >> 1;
        if(ql <= mid) {
            update_set(l,mid,cl(id),ql,qr,v);
        }
        if(qr > mid) {
            update_set(mid+1,r,cr(id),ql,qr,v);
        }
        pull(id,l,r);
    }
    void update_add(int l,int r,int id,int ql,int qr,int v) {
        push(id,l,r);
        if(ql<=l&&r<=qr) {
            tag_add[id] += v;
            return;
        }
        int mid = (l+r) >> 1;
        if(ql <= mid) {
            update_add(l,mid,cl(id),ql,qr,v);
        }
        if(qr > mid) {
            update_add(mid+1,r,cr(id),ql,qr,v);
        }
        pull(id,l,r);
    }
    void update_add(int val,int l,int r) {
        update_add(1,n,1,l,r,val);
    }
    void update_set(int val,int l,int r) {
        update_set(1,n,1,l,r,val);
    }
};
void solve() {
    int n,q;
    cin >> n >> q;
    seg_T t(n);
    t.input_datas();
    t.build();
    for(int i = 0;i<q;i++) {
        int op=0;
        cin >> op;
        int l,r;
        cin >> l >> r;
        if(op == 1) {
            int val;
            cin >> val;
            t.update_add(val,l,r);
        } else if(op == 2) {
            int val;
            cin >> val;
            t.update_set(val,l,r);
        } else if(op == 3) {
            cout << t.query(l,r) << endl;
        }
    }
}
signed main() {
    solve();
}
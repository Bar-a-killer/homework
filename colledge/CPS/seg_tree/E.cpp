#include <bits/stdc++.h>
using namespace std;
#define int long long
#define cl(X) (X<<1)+1
#define cr(X) (X<<1)+2
#define INF 1e18
#define pii pair<int,int>
class seg_T{
    public:
    int n;
    vector<int> seg_tree;
    vector<int> datas;
    seg_T(int a) {
        seg_tree.resize(a*4+5);
        n = a;
        for(int i = 0;i<n*4;i++) {
            seg_tree[i] = INF;
        }
        datas.resize(n);
    }
    void input_datas() {
        for(int i = 0;i < n;i++) {
            cin >> datas[i];
        }
    }
    void pull(int id) {
        seg_tree[id] = max(seg_tree[cl(id)],seg_tree[cr(id)]); 
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
            res = max(res,take(l,mid,sl,sr,cl(id)));
        }
        if(sr > mid) {
            res = max(res,take(mid+1,r,sl,sr,cr(id)));
        }
        return res;
    }
    int take(int l,int r) {
        return take(0,n-1,l,r,0);
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
    int search(int l,int r,int id,int targ) {
        if(l == r && datas[l] >= targ) {
            update(l,datas[l]-targ);
            return l;
        }
        int mid = (l+r) >> 1;
        if(targ <= seg_tree[id]) {
            int tt = search(l,mid,cl(id),targ);
            if(tt == -1)
                return search(mid+1,r,cr(id),targ);
            else return tt;
        } else {
            //cout << "!" << id << endl;
            return -1;
        }
    }
    int search(int targ) {
        if(seg_tree[0] < targ) return -1;
        return search(0,n-1,0,targ);
    }
    void update(int pos,int val) {
        datas[pos] = val;
        update(0,n-1,pos,0);
    }
    void throwout() {
        for(int i = 0;i<n*2-1;i++) {
            cout << i << ":" << seg_tree[i] << " ";
        }
        cout << endl;
    }
};
signed main() {
    int n,m;
    cin >> n >> m;
    seg_T t(n);
    t.input_datas();
    t.build();
    //t.throwout();
    for(int i = 0;i < m;i++) {
        int tmp;
        cin >> tmp;
        cout << t.search(tmp)+1 << " ";
        //t.throwout();
    }
}
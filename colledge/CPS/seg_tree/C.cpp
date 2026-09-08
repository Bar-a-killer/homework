#include<bits/stdc++.h>
using namespace std;
#define int long long
#define cl(X) (X<<1)+1
#define cr(X) (X<<1)+2
#define INF 1e18
#define pii pair<int,int>
class seg_T{
    public:
    int n;
    vector<pii> seg_tree;
    vector<int> datas;
    seg_T(int a) {
        seg_tree.resize(a*4+5);
        n = a;
        datas.resize(n);
    }
    void input_datas() {
        for(int i = 0;i < n;i++) {
            cin >> datas[i];
        }
    }
    void pull(int id) {
        seg_tree[id].first = max({seg_tree[cl(id)].first,seg_tree[cl(id)].second+seg_tree[cr(id)].first}); 
        seg_tree[id].second = seg_tree[cl(id)].second+seg_tree[cr(id)].second;
    }
    void build(int id,int l,int r) {
        if(l==r) {
            seg_tree[id].first = max((int)0,datas[l]);
            seg_tree[id].second = datas[l];
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
    pii take(int l,int r,int sl,int sr,int id) {
        if(sl<=l&&r<=sr){
            return seg_tree[id];
        }
        int mid = (l+r) >> 1;
        pii res = {0,0};
        if(sl <= mid) {
            pii ltmp = take(l,mid,sl,sr,cl(id));
            res.first = max({res.first,res.second+ltmp.first,ltmp.first});
            res.second += ltmp.second;
        }
        if(sr > mid) {
            pii rtmp = take(mid+1,r,sl,sr,cr(id));
            res.first = max({res.first,res.second+rtmp.first});
            res.second += rtmp.second;
        }
        return res;
    }
    int take(int l,int r) {
        return take(0,n-1,l,r,0).first;
    }
    void update(int l,int r,int pos,int id) {
        if(l == r) {
            seg_tree[id].first = max(datas[pos],(int)0);
            seg_tree[id].second = datas[pos];
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
        for(int i = 0;i<n*4;i++) {
            cout << seg_tree[i].first << "|" << seg_tree[i].second << " ";
        }
        cout << endl;
    }
};
signed main() {
    int n,q;
    cin >> n >> q;
    seg_T t(n);
    t.input_datas();
    t.build();
    //t.throwout();
    for(int i = 0;i<q;i++) {
        int op=0;
        cin >> op;
        int a,b;
        cin >> a >> b;
        if(op == 2) {
            cout << t.take(a-1,b-1) << endl;
        }
        if(op == 1) {
            t.update(a-1,b);
        }
        //t.throwout();
    }
}
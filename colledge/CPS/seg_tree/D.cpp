#include<bits/stdc++.h>
using namespace std;
#define int long long
#define cl(X) (X<<1)+1
#define cr(X) (X<<1)+2
#define INF 1e18
struct bar{
    int pre,post,mx,total;
};
class seg_T{
    public:
    int n;
    vector<bar> seg_tree;
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
    void init_(int id,int pos) {
        seg_tree[id].pre = max(datas[pos],(int)0);
        seg_tree[id].post = max(datas[pos],(int)0);
        seg_tree[id].mx = max(datas[pos],(int)0);
        seg_tree[id].total = datas[pos];
        return;
    }
    void pull(int id) {
        bar l = seg_tree[cl(id)],r = seg_tree[cr(id)];
        seg_tree[id].pre = max({l.pre,l.total+r.pre});
        seg_tree[id].post = max({r.post,r.total+l.post}); 
        seg_tree[id].mx = max({l.mx,r.mx,l.post+r.pre});
        seg_tree[id].total = seg_tree[cl(id)].total+seg_tree[cr(id)].total;
    }
    void build(int id,int l,int r) {
        if(l==r) {
            init_(id,l);
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
    void update(int l,int r,int pos,int id) {
        if(l == r) {
            init_(id,pos);
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
    bar merge(bar l,bar r) {
        bar res;
        res.pre = max(l.pre, l.total + r.pre);
        res.post = max(r.post, r.total + l.post);
        res.mx = max({l.mx, r.mx, l.post + r.pre});
        res.total = l.total + r.total;
        return res;
    }
    bar take(int l,int r,int sl,int sr,int id) {
        if(sl<=l&&r<=sr){
            return seg_tree[id];
        }
        int mid = (l+r) >> 1;
        bar res = {0,0};
        if(sr <= mid) {
            return take(l,mid,sl,sr,cl(id));
        }
        if(sl > mid) {
            return take(mid + 1, r, sl, sr, cr(id));
        }
        bar ltmp = take(l,mid,sl,sr,cl(id));
        bar rtmp = take(mid+1,r,sl,sr,cr(id));

        return merge(ltmp,rtmp);
    }
    int take(int l,int r) {
        return take(0,n-1,l,r,0).mx;
    }
    void throwout() {
        for(int i = 0;i<n*4;i++) {
            bar s = seg_tree[i];
            cout << s.pre << "|" << s.total << "|" << s.mx << " ";
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
        int a,b;
        cin >> a >> b;
        t.update(a-1,b);
        cout << t.take(0,n-1) << endl;
    }
}
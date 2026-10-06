struct AreaofRectangles{
#define cl(x) (x<<1)
#define cr(x) (x<<1|1)
    int n, id, sid;
    pair<int,int> tree[MXN<<3];   // count, area
    vector<int> ind;
    tuple<int,int,int,int> scan[MXN<<1];
    void puint(int i, int l, int r){
        if(tree[i].first)  tree[i].second = ind[r+1] - ind[l];//當前區間有被做加值
        else if(l != r){//沒有就直接拿兩個子節點的第二個數字
            int mid = (l+r)>>1;
            tree[i].second = tree[cl(i)].second + tree[cr(i)].second;
        }
        else    tree[i].second = 0;
    }
    void upd(int i, int l, int r, int ql, int qr, int v){
        if(ql <= l && r <= qr){
            tree[i].first += v;
            puint(i, l, r); return;
        }
        int mid = (l+r) >> 1;
        if(ql <= mid) upd(cl(i), l, mid, ql, qr, v);
        if(qr > mid) upd(cr(i), mid+1, r, ql, qr, v);
        puint(i, l, r);
    }
    void init(int _n){
        n = _n; id = sid = 0;
        ind.clear(); ind.resize(n<<1);
        fill(tree, tree+(n<<2), make_pair(0, 0));
    }
    void addRectangle(int lx, int ly, int rx, int ry){
        ind[id++] = lx; ind[id++] = rx;
        scan[sid++] = make_tuple(ly, 1, lx, rx);
        scan[sid++] = make_tuple(ry, -1, lx, rx);
    }
    int solve(){
        sort(ind.begin(), ind.end());
        ind.resize(unique(ind.begin(), ind.end()) - ind.begin());//離散化
        sort(scan, scan + sid);
        int area = 0, pre = get<0>(scan[0]);
        for(int i = 0; i < sid; i++){
            auto [x, v, l, r] = scan[i];
            area += tree[1].second * (x-pre);//
            upd(1, 0, ind.size()-1, lower_bound(ind.begin(), ind.end(), l)-ind.begin(), lower_bound(ind.begin(),ind.end(),r)-ind.begin()-1, v);
            pre = x;
        }
        return area;
}   }rect;
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define piii pair<int,pair<int,int>>
struct DSU {
    vector<int> f, sz;
    int cnt;
    DSU(int n) : f(n), sz(n) {
        for (int i = 0; i < n; i++) {
            f[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        if (x == f[x]) return x;
        return f[x] = find(f[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y])
            swap(x, y);
        f[y] = x;
        sz[x] += sz[y];
        cnt--;
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    int groups() {
        return cnt;
    }
};
signed main() {
    int n,m;
    while(cin >> n >> m) {
        if(n==0 && m==0) return 0;
        piii a;
        priority_queue<piii,vector<piii>,greater<piii>> pq;
        while(m--) {
            cin >> a.second.second >> a.second.first >> a.first;
            pq.push(a);
        }
        vector<int> ans;
        DSU dsu(n);
        while(!pq.empty()) {
            auto [w, uv] = pq.top(); pq.pop();
            int u = uv.first, v = uv.second;
            if(dsu.same(u,v)) ans.push_back(w);
            else dsu.merge(u,v);
        }
        if(ans.empty()) cout << "forest\n";
        else {
            cout << ans[0];
            for(int i = 1;i < (int)ans.size();i++) cout << ' ' << ans[i];
            cout << '\n';
        } 
    }
}

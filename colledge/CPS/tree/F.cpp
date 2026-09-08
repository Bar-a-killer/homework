#include <bits/stdc++.h>
using namespace std;
#define yuri ios::sync_with_stdio(0),cin.tie(0);
#define int long long
typedef pair<int,int> pii;
#define endl "\n"
const int maxn = 100005;
vector<pii> v_all[maxn];
vector<pii> v[maxn];
int in[maxn];
int out[maxn];
int vis[maxn];
int anc[maxn][21];
int timee = 1;
int lcaw[maxn][21] = {0};
void dfs1(int r,int fa) {
    in[r] = timee++;
    anc[r][0] = fa;
    
    for(auto nxt:v[r]) {
        if(nxt.first != fa) {
            lcaw[nxt.first][0] = nxt.second;
            dfs1(nxt.first,r);
        } 
    }
    out[r] = timee++;
}
bool is_auc(int a,int b) {
    return in[a] < in[b] && out[a] > out[b];
}
int lca(int a,int b) {
    if(is_auc(a,b)) return a;
    if(is_auc(b,a)) return b;
    for(int i = 20;i >= 0;i--) {
        if(anc[a][i]  && anc[a][i] != b && !is_auc(anc[a][i], b))
            a = anc[a][i];
    }
    return anc[a][0];
}
set<pair<int,int>> in_mst;
struct m {
    int w,u,v;
    bool operator>(const m& o) const {
        return w > o.w;
    }
};
int toans = 0;
int viss[maxn] = {0};
void mst() {
    priority_queue<m,vector<m>,greater<m>> que;
    viss[1] = 1;
    for(pii i:v_all[1]) {
        que.push({i.second,1,i.first});
    }
    while(!que.empty()) {
        auto to = que.top(); que.pop();
        if(viss[to.v]) continue;
        viss[to.v] = 1;
        for(pii i:v_all[to.v]) {
            que.push({i.second, to.v, i.first});
        }
        v[to.u].push_back({to.v,to.w});
        v[to.v].push_back({to.u,to.w});
        in_mst.insert({to.u, to.v});
        in_mst.insert({to.v, to.u});
        toans += to.w;
    }
}
int lca_maxw(int a, int b) {
    int l = lca(a, b);
    int maxw = 0;
    for(int i = 20; i >= 0; i--) {
        if(anc[a][i] && anc[a][i] != l && !is_auc(anc[a][i], l)) {
            maxw = max(maxw, lcaw[a][i]);
            a = anc[a][i];
        }
    }
    if(a != l) maxw = max(maxw, lcaw[a][0]);
    for(int i = 20; i >= 0; i--) {
        if(anc[b][i] && anc[b][i] != l && !is_auc(anc[b][i], l)) {
            maxw = max(maxw, lcaw[b][i]);
            b = anc[b][i];
        }
    }
    if(b != l) maxw = max(maxw, lcaw[b][0]);
    return maxw;
}
signed main() {
    yuri;
    int n,m;
    cin >> n >> m;
    vector< tuple<int,int,int> > input;
    for(int i = 0;i < m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v_all[a].push_back({b,c});
        v_all[b].push_back({a,c});
        input.push_back({a,b,c});
    }
    mst();
    dfs1(1,0);
    for(int j = 1; j <= 20; j++) {
        for(int i = 1; i <= n; i++) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
            lcaw[i][j] = max(lcaw[i][j - 1],lcaw[anc[i][j - 1]][j - 1]);
        }
    }
    for(auto [a,b,c]:input) {
        if(in_mst.count({a, b})) {
            cout << "YES" << endl;
        } else {
            if(toans - lca_maxw(a,b) + c == toans)
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
    }
    return 0;
}
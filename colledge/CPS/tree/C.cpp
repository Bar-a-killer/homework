#include <bits/stdc++.h>
using namespace std;
#define yuri ios::sync_with_stdio(0),cin.tie(0);
#define int long long
#define endl "\n"
typedef pair<int,int> pii;
const int maxn = 200005;
vector<pii> v[maxn];
int in[maxn];
int out[maxn];
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
void solve(int n) {
    timee = 1;
    for(int i = 1; i <= n; i++) {
        v[i].clear();
        fill(anc[i], anc[i]+21, 0);
        fill(lcaw[i], lcaw[i]+21, 0);
    }
    int m;
    for(int i = 0;i < n-1;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs1(1,0);
    for(int j = 1; j <= 20; j++) {
        for(int i = 1; i <= n; i++) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
            lcaw[i][j] = max(lcaw[i][j - 1],lcaw[anc[i][j - 1]][j - 1]);
        }
    }
    cin >> m;
    for(int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        cout << lca_maxw(a,b) << endl;
    }
}
signed main() {
    yuri;
    int n;
    while(cin >> n) {
        if(n == 0) break;
        solve(n);
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define yuri ios::sync_with_stdio(0),cin.tie(0);
#define int long long
const int maxn = 400005;
vector<int> v[maxn];
int in[maxn];
int out[maxn];
int vis[maxn];
int anc[maxn][20];
int timee = 1;
void dfs1(int r,int fa) {
    in[r] = timee++;
    anc[r][0] = fa;
    for(auto nxt:v[r]) {
        if(nxt != fa)
            dfs1(nxt,r);
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
        if(anc[a][i] && !is_auc(anc[a][i], b))
            a = anc[a][i];
    }
    return anc[a][0];
}
int ans[maxn];
int dfs(int now, int fa){
    int diff = vis[now];
    for(auto nxt : v[now]){
        if(nxt == fa) continue;
        diff += dfs(nxt, now);
    }
    return ans[now] = diff;
}
signed main() {
    yuri;
    int n;
    cin >> n;
    for(int i = 0;i < n-1;i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs1(1,0);
    for(int j = 1; j <= log2(n); j++) {
        for(int i = 1; i <= n; i++) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }

    for(int i = 1;i < n;i++) {
        int lcaa = lca(i,i+1);
        vis[i]++;
        vis[i+1]++;
        vis[lcaa]--;
        if(lcaa != 1) vis[anc[lcaa][0]]--;
    }
    dfs(1,-1);
    for(int i = 1;i <= n;i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
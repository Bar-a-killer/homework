#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
vector<int> edge[N];
vector<int> tur,turr,subt;
int dfs1(int fa,int now){
    int ans = 0;
    for(auto i:edge[now]) {
        if(i != fa) {
            ans += dfs1(now,i);
        }
    }
    subt[now] = ans+1;
    return ans+1;
}
int dfs(int fa,int now){
    int ans = 0;
    for(auto i:edge[now]) {
        if(i != fa) {
            ans += dfs(now,i)+subt[i];
        }
    }
    tur[now] = ans;
    return ans;
}
int n;
void dfs2(int fa,int now) {
    if(fa == -1) {
        turr[now] = tur[now];
    } else 
        turr[now] = turr[fa]-subt[now]+(n-subt[now]);
    for(auto i:edge[now]) {
        if(i == fa) continue;
        dfs2(now,i);
    }
}
signed main() {
    cin >> n;
    tur.resize(n);
    turr.resize(n);
    subt.resize(n);
    for(int i = 0;i < n-1;i++) {
        int u,v;cin >> u >> v;
        u--;v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs1(-1,1);
    dfs(-1,1);
    dfs2(-1,1);
    for(auto i:turr) cout << i << " ";
}

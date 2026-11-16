#include<bits/stdc++.h>
using namespace std;
#define int long long
int n = 2e5+10;
vector<vector<int>> tree(n);
int edp1,edp2;
int edp1t = 0;
int edp2t = 0;
vector<int> dis(n,0);
void dfs(int fa,int now,int deep,int tg) {
    for(auto i:tree[now]) {
        if(i != fa)
            dfs(now,i,deep+1,tg);
    }
    if(deep > edp1t && tg==1) {
        edp1t = deep;
        edp1 = now;
    } else if(deep > edp2t && !tg) {
        edp2t = deep;
        edp2 = now;
    }
    if(tg == 3) {
        dis[now] = max(dis[now],deep);
    }
}
signed main() {
    int n;
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v;cin >> u >> v;
        u--;v--;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }
    dfs(-1,0,0,1);
    dfs(-1,edp1,0,0);
    dfs(-1,edp2,0,3);
    dfs(-1,edp1,0,3);
    for(int i = 0;i < n;i++) cout << dis[i] << " ";
}

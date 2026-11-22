#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    vector<int> deg(n,0),cnt(n,1);
    vector<bool> vis(n,0);
    for(int i = 1;i < n;i++) {
        int u,v;cin >> u >> v;
        u--;v--;
        tree[v].push_back(u);
        tree[u].push_back(v);
        deg[u]++;deg[v]++;
    }
    queue<int> que;
    for(int i = 0;i < n;i++) {
        if(deg[i] == 1) 
            que.push(i);
    }
    while(!que.empty()) {
        int me = que.front();que.pop();
        vis[me] = 1;
        if(cnt[me]*2 >= n) {
            cout << me+1 << endl;
        }
        for(int boss:tree[me]) {
            if(vis[boss]) continue;
            cnt[boss] += cnt[me];
            deg[boss]--;
            if(deg[boss] == 1) que.push(boss);
        }
    }
}

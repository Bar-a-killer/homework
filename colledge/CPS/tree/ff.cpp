#include<bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int now,vector<pair<int,int>>& edge,string& s) {
    if(edge[now] == make_pair(0LL,0LL)) {
        return 0;
    }
    int ans = 1e18;
    if(edge[now].first) ans = min(ans,dfs(edge[now].first,edge,s)+(s[now-1]!='L'));
    if(edge[now].second) ans = min(ans,dfs(edge[now].second,edge,s)+(s[now-1]!='R'));
    return ans;
} 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int,int>> edge;
    edge.push_back({0,0});
    int u,v;
    for(int i = 0;i < n;i++) {
        cin >> u >> v;
        edge.push_back({u,v});
    }
    cout << dfs(1,edge,s) << '\n';
}
signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}

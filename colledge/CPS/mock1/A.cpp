#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first 
#define s second
#define INF 1e8
#define yuri ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
struct edge{int v,w;};
void solve() {
    priority_queue<pii,vector<pii>,greater<pii>> q[300006];
    int n,m;
    cin >> n >> m;
    int c[300006];
    bool vis[300006] = {0};
    for(int i = 0;i < n;i++) {
        cin >> c[i];
        for(int j = 0;j < i;j++) {
            q[i].push({(c[i]-c[j])*(c[i]-c[j]),j});
            q[j].push({(c[i]-c[j])*(c[i]-c[j]),i});
        }
    }
    
    
    
}
signed main() {
    solve();
}
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first 
#define s second
#define INF (long long)4e18
#define yuri ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
struct edge{int v,u,w;};
void solve() {
    int n,m,q;
    cin >> n >> m >> q;
    int dis[n + 1][n + 1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v]=min(dis[u][v], w);
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][k] < INF/2 && dis[k][j] < INF/2)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int zero[n + 1] = {0};
    for(int i = 0; i < n; i++){
        if(dis[i][i] < 0){
            zero[i] = 1;
        }
    }
    while(q--){
        int u, v;
        int bad = 0;
        cin >> u >> v;
        if(dis[u][v] >= INF/2) { 
            cout << "Impossible"  << endl;
            continue;
        }
        else {
            for(int i = 0; i < n; i++){
                if(zero[i] && dis[u][i] <= INF/2 && dis[i][v] <= INF/2){
                    cout << "-Infinity" << endl;
                    bad = 1;
                    break;
                }
            }
            if(bad) continue;
            cout << dis[u][v] << endl;
        }
    }
    
}
signed main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}
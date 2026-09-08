#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define f first
#define INF 1e18
#define s second
#define MOD 1000000007
#define FOR(I,N) for(int I=0;I<(N);I++)
#define yuri ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
vector<vector<int>> edge(1e5);
vector<int> path;
void dfs(int x){
    while(!edge[x].empty()){
        int u = edge[x].back();
        edge[x].pop_back();
        dfs(u);
    }
    path.push_back(x);
}
typedef struct node {
    int in = 0,out = 0;
    vector<int> children;
};
void solve() {
    int n,m;
    cin >> n >> m;
    vector<node> graph(n+1);
    while(m--) {
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        graph[a].children.push_back(b);
        graph[b].in++;
        graph[a].out++;
    }
    
    for(int i = 1;i <= n;i++) {
        if(graph[i].out == graph[i].in+1) {
            tupo.push(i);
        }
    }
    dfs(st);
    while(!tupo.empty()) {
        int now = tupo.top();
        tupo.pop();
        for(int i:graph[now].children) {
            tupo.push(i);
        }
    }
    cout << graph[n].way << endl;
}
signed main() {
    yuri;
    int t;
    cin >> t;
    while(t--)
        solve();
}
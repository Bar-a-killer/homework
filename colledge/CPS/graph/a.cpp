#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define f first
#define INF 1e18
#define s second
#define FOR(I,N) for(int I=0;I<(N);I++)
#define yuri ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef struct node {
    int in = 0;
    vector<int> children;
};
void solve() {
    int n,m;
    cin >> n >> m;
    vector<node> graph(n+1);
    while(m--) {
        int a,b;
        cin >> a >> b;
        graph[a].children.push_back(b);
        graph[b].in++;
    }
    queue<int> tupo;
    vector<int> ans;

    for(int i = 1;i <= n;i++) {
        if(graph[i].in == 0) {
            tupo.push(i);
        }
    }
    while(!tupo.empty()) {
        int now = tupo.front();
        tupo.pop();
        ans.push_back(now);
        for(int i:graph[now].children) {
            graph[i].in --;
            if(graph[i].in == 0) {
                tupo.push(i);
            }
        }
    }
    for(node i:graph) {
        if(i.in != 0) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    for(int i:ans) {
        cout << i << " ";
    }
}
signed main() {
    yuri;
    solve();
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define f first
#define INF 1e18
#define s second
#define FOR(I,N) for(int I=0;I<(N);I++)
#define yuri ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(),(x).end()
typedef struct node {
    int in = 0;
    vector<int> children;
    int step = 0;
    int num = 0;
    bool iszero = 0;
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
    bool dec = 0;
    for(int i = 1;i <= n;i++) {
        if(graph[i].in == 0) {
            if(dec) {
                cout << "No" << endl;
                return;
            }
            tupo.push(i);
            dec = 1;
        }
    }
    graph[0].iszero = 1;
    int r = 1;
    while(!tupo.empty()) {
        if(tupo.size() > 1) {
            cout << "No" << endl;
            return;
        }
        int now = tupo.front();
        tupo.pop();
        graph[now].num = r++;
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
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    for(node i:graph) {
        if(i.iszero) continue;
        cout << i.num << " ";
    }
}
signed main() {
    yuri;
    solve();
}
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first 
#define s second
#define yuri ios::sync_with_stdio(0),cin.tie(0);
#define maxn 300001
using namespace std;

struct charact {
    int lis[26] = {0};
};

signed main() {
    int n,m;
    cin >> n >> m;
    string str;
    cin >> str;
    set<int> edge[maxn];
    int lengths[maxn] = {0};
    int a,b;
    int deg[maxn] = {0};
    queue<int> q;
    vector<charact> count(maxn);
    int maxs = 0;
    
    for(int i = 0;i < m;i++) {
        cin >> a >> b;
        bool det = 0;
        if(edge[a].count(b) > 0) {
            continue;
        }
        if(a == b) {
            cout << -1 << endl;
            return 0;
        }
        edge[a].insert(b);
        deg[b]++;
    }
    for(int i = 1;i <= n;i++) {
        if(deg[i]==0) {
            q.push(i);
        }
    } //n
    while(!q.empty()) {
        int u = q.front();q.pop();
        count[u].lis[str[u-1]-'a']++;
        maxs = max(count[u].lis[str[u-1]-'a'],maxs);
        for(int i:edge[u]) {
            for(int j = 0;j < 26;j++) {
                count[i].lis[j] = max(count[i].lis[j],count[u].lis[j]);
            }
            if(--deg[i] == 0) q.push(i);
        }
    }
    for(int i:deg) {
        if(i != 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << maxs << endl;
}
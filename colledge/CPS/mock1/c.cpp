#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define yuri ios::sync_with_stdio(0),cin.tie(0);
vector<int> in(1000005,0);
vector<int> out(1000005,0);
vector<int> path;
vector<int> edge[1000005];
set<int> used;
void dfs(int x){
    while(!edge[x].empty()){
        int u = edge[x].back();
        edge[x].pop_back();
        dfs(u);
    }
    path.push_back(x);
}
void solve() {
    int n;
    cin >> n;
    vector<int> datas(n);
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        datas[i] = x;
        out[x]++;
        used.insert(x);
    }
    for(int i = 0;i < n;i++) {
        int y;
        cin >> y;
        in[y]++;
        edge[datas[i]].push_back(y);
        used.insert(y);
    }
    
    int ans_in = 0, ans_out = 0;
    int min_good = -1;
    bool bad = false;
    for(int v : used) {
        //cout << v << " " << in[v] << " " << out[v] << endl;
        int diff = in[v] - out[v];
        if(diff > 0) {
            if(ans_in || diff > 1) { bad = true;break; }
            ans_in = v;
        }
        else if(diff < 0) {
            if(ans_out || diff < -1) { bad = true;break; }
            ans_out = v;
        }
    }
    if(bad) {
        cout << -1 << endl;
        return;
    }
    dfs(ans_out ? ans_out : *used.begin());
    if(path.size() != n+1) {
        cout << -1 << endl;
        return;
    }
    if(!ans_in && !ans_out) {
        cout << *used.begin() << " " << *used.begin() << endl;
        return;
    }
    else if(!(ans_in ^ ans_out)) {
        cout << -1 << endl;
        return;
    }
    cout << ans_out << " " << ans_in << endl;
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
        for(int v : used) {
            edge[v].clear();
            in[v] = out[v] = 0;
        }
        used.clear();
        path.clear();
    }
}
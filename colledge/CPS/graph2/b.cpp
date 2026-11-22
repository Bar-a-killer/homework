#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > graph[n+1];
    while(m--) {
        int s,e,w;
        cin >> s >> e >> w;
        graph[s].push_back({w,e});
        graph[e].push_back({w,s});
    }
    int ans = 0;
    set<int> viss;
    viss.insert(1);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> >> pq;
    for(auto i:graph[1]) {
        pq.push(i);
    }
    while(viss.size() < n && !pq.empty()) {
        auto i = pq.top();
        pq.pop();
        if(viss.find(i.second) != viss.end()) continue;
        ans += i.first;
        viss.insert(i.second);
        for(auto j:graph[i.second]) pq.push(j);
    }
    if(viss.size() >= n)
        cout << ans << endl;
    else cout << "IMPOSSIBLE\n" << endl;
}
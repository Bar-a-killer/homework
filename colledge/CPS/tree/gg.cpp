#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
vector<int> deep(N);
vector<int> rdeep(N);
vector<int> high(N);
vector<int> edge[N];
int n,u,v;
int dfs(int boss,int now) {
    if(boss == -1) deep[now] = 0;
    else deep[now] = deep[boss] + 1;
    int rval = -1;
    for(auto i : edge[now]) {
        if(i == boss) continue;
        rval = max(rval,dfs(now,i));
        high[now] = max(high[now],high[i]+1);
    }
    if(rval != -1) rval++;
    else if(now == v) rval = 0;
    rdeep[now] = rval;
    return rval;
}
int dfs1(int boss,int now) {
    if(deep[now] > rdeep[now]) {
        int run = rdeep[now] + high[now];
        int hunt = deep[now] + high[now];
        return hunt - 1;
    } else {
        for(auto i: edge[now]) {
            if(i == boss) continue;
            if(rdeep[i] == -1) continue;
            return dfs1(now,i);
        }
    }
    return -1000;
}
signed main() {
    cin >> n >> v >> u;
    for(int i = 0;i < n-1;i++) {
        int s,e;cin >> s >> e;
        edge[s].push_back(e);
        edge[e].push_back(s);
    }
    dfs(-1,u);
    cout << dfs1(-1,u) << endl;
}

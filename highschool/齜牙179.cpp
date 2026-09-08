#include <bits/stdc++.h>
using namespace std;

int dfs[30001] = {0};
int low[30001];
vector< vector<int> > G(30001);
int cnt = 0;
int maxtree = -1;
int ans = 0;

void DFS(int pa,int u) {
	dfs[u] = low[u] = ++cnt;
	int r = 0;
	int tmc = dfs[u];
	for(int v : G[u]) {
		if(v == pa) continue;
		if(dfs[v] == 0) {
			DFS(u,v);
			low[u] = min(low[u],low[v]);
			if(low[v] >= dfs[u] && pa != -1) {
				r += cnt - tmc;
			}
			tmc = cnt;
		}
		else if(dfs[v] < dfs[u])
			low[u] = min(low[u],dfs[v]);
	}
	if(maxtree < r && r!=0) {
		maxtree = r;
		ans = u;
	}
}
int main() {
	int N,M,ftr,chd;
	cin >> N >> M;
	while(M--) {
		cin >> ftr >> chd;
		G[ftr].push_back(chd);
		G[chd].push_back(ftr);
	}
	int k;
	cin >> k;
	DFS(-1,k);
	if(ans != 0) 
		cout << ans << " " << cnt - maxtree << endl;
	else 
		cout << ans << endl;
}
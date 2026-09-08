#include<bits/stdc++.h>
using namespace std;

bool ans = 1;
void dfs(vector<vector<bool>> link,vector<int> value,int parent) {
	if(!ans) 
		return;
	int n = link[0].size();
	while(n--) {
		if(link[parent][n] == 1) {
			if(value[n] == -1) {
				value[n] = !value[parent];
				dfs(link,value,n);
			}
			else if(value[n] == value[parent]) {
				ans = 0;
				return;
			}
		}
	}
}
int main() {
	int T,n,m,nodn,nodo;
	cin >> T;
	while(T--) {
		cin >> n;
		cin >> m;
		vector<int> value(n);
		for(int i=0;i<n;i++)
			value[i] = -1;
		vector<vector<bool>> link(n,vector<bool>(n));
		while(m--) {
			cin >> nodn >> nodo;
			link[nodn][nodo] = 1;
			link[nodo][nodn] = 1;
		}
		value[0] = 0;
		dfs(link,value,0);
		if(ans) 
			cout << "NORMAL." << endl;
		else
			cout << "RAINBOW." << endl;
		ans = 1;
	}
}
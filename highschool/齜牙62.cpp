#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> pos;
vector<vector<int>> possi;
char datas[9][9];
int dfs(pair<int,int> i) {
	for(int k=0;k<9;k++) {
		for(int j=0;j<9;j++) {
			if(datas[i.first][j] == '.')
				possi[i.first][j] = 11;
			if(datas[j][i.first] == '.')
				possi[j][i.first] = 11;
		}
	}
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		pair<int,int> tmp;
		
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				cin >> datas[i][j];
				if(datas[i][j] == '.') {
					tmp.first = i;
					tmp.second = j;
					pos.push_back(tmp);
				}
			}
		}
		for(auto i : pos) {
			vector<int> tmp,tmp1;
			for(int j=0;j<9;j++)
				tmp.push_back(j);
			for(int j=0;j<9;j++) {
				if(datas[i.first][j] != '.')
					tmp[datas[i.first][j]-47] = 10;
				if(datas[j][i.first] != '.')
					tmp[datas[j][i.first]-47] = 10;
			}
			for(int j=0;j<9;j++)
				if(tmp[j] != 10)
					tmp1.push_back(j);	
		    possi.push_back(tmp);
		}
	}
	
}
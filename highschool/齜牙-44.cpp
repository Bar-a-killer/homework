#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int bfs(vector<vector<char>>& themap, int t, int w) {
    int rows = themap.size();
    int cols = themap[0].size();
    queue<pair<int, int>> q;
    q.push({t, w});
    themap[t][w] = '#';
    int cnt = 1;
    int sz;
    pair<int,int> tmp;
    while (!q.empty()) {
    	sz = q.size();
    	while(sz--) {
    		tmp = q.front();
	        q.pop();
	        for (int d = 0; d < 4; d++) {
	            int next_t = tmp.first + dx[d];
	            int next_w = tmp.second + dy[d];
	            if (next_t < 0 || next_t >= rows || next_w < 0 || next_w >= cols || themap[next_t][next_w] == '#') {
	                continue;
	            }
		        if(themap[next_t][next_w] == '@') {
		        	return cnt;
		        }
	            themap[next_t][next_w] = '#';
	            q.push({next_t, next_w});
	        }
    	}
        cnt++;
    }
    return 0;
}
int main() {
    int n,ans = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        int tall,wight;
        cin >> tall >> wight;
        vector<vector<char>> themap(tall, vector<char>(wight));
        int tt,ll;
        for(int t=0;t<tall;t++) {
            for(int w=0;w<wight;w++) {
                cin >> themap[t][w];
                if(themap[t][w] == 'K') {
                    tt = t;
                    ll = w;
                }
            }
        }

        ans = bfs(themap,tt,ll);
        if(ans == 0)
            cout << "= =\"" << endl;
        else
            cout << ans << endl;
    }
}

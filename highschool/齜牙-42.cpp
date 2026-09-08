#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(vector<vector<char>>& themap, int t, int w) {
    if (t < 0 || t >= themap.size() || w < 0 || w >= themap[0].size() || themap[t][w] == '#') {
        return;
    }
    themap[t][w] = '#';
    for(int d=0;d<4;d++) {
        dfs(themap, t + dx[d], w + dy[d]);
    }
}
int main() {
    int n,ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int tall,wight;
        cin >> tall >> wight;
        vector<vector<char>> themap(tall, vector<char>(wight));
        for(int t=0;t<tall;t++) {
            for(int w=0;w<wight;w++) {
                cin >> themap[t][w];
            }
        }
        for(int t=0;t<tall;t++) {
            for(int w=0;w<wight;w++) {
                if(themap[t][w] == '.') {
                    dfs(themap, t, w);
                    ans ++;
                }
            }
        }
        cout << ans << endl;
        ans = 0;
    }
}

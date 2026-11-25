#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<char>> bux(vector<vector<char>> cha,int x,int y) {
    for(int i = 0;i < 8;i++) {
        cha[x][i] = '#';
        cha[i][y] = '#';
        if(x-i >= 0 && y-i >= 0) {
            cha[x-i][y-i] = '#';
        }
        if(x-i >= 0 && y+i < 8) {
            cha[x-i][y+i] = '#';
        }
        if(x+i < 8 && y-i >= 0) {
            cha[x+i][y-i] = '#';
        }
        if(x+i < 8 && y+i < 8) {
            cha[x+i][y+i] = '#';
        }
    }
    return cha;
}
int ans = 0;
void solve(vector<vector<char>> mp,int pos,int cnt) {
    if(cnt == 8) {
        ans++;
        return;
    }
    while(pos < 63) {
        pos++;
        if(mp[pos/8][pos%8] == '.') {
            solve(bux(mp,pos/8,pos%8),pos,cnt+1);
        }     
    }
}
signed main() {
    vector<vector<char>> ori(8,vector<char>(8));
    stack<pair<int,int>> st;
    for(int i = 0;i < 8;i++) {
        for(int j = 0;j < 8;j++) {
            cin >> ori[i][j];
        }
    }
    solve(ori,-1,0);
    cout << ans << endl;
}

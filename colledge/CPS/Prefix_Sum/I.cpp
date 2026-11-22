#include<bits/stdc++.h>
using namespace std;
#define int long long
bool change[1010][1010] = {0};
bool matrix[1010][1010];
signed main() {
    int n,m;cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            char tmp;
            cin >> tmp;
            matrix[i][j] = tmp-'0';
        }
    }
    int q;cin >> q;
    while(q--) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        change[x2+1][y2+1] = !change[x2+1][y2+1];
        change[x1][y1] = !change[x1][y1];
        change[x1][y2+1] = !change[x1][y2+1];
        change[x2+1][y1] = !change[x2+1][y1];
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(change[i][j]) {
                change[i+1][j] = !change[i+1][j];
                change[i][j+1] = !change[i][j+1];
                change[i+1][j+1] = !change[i+1][j+1];
            }
            cout << (matrix[i][j]^change[i][j]);
        }
        cout << '\n';
    }
}

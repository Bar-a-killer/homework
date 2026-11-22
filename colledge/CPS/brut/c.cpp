#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx = 1e7;
int cable[mx] = {0};
void solve() {
        int n;
        cin >> n;
        for(int i = 0;i*i <= n;i++) {
            for(int j = 0;i*i+j*j <= n;j++) {
                if(cable[n-i*i-j*j] != -1) {
                    int c = cable[n-i*i-j*j]; 
                    cout << i << " " << j << " " << c << " " << (int)sqrt(n-i*i-j*j-c*c) << '\n';
                    return;
                }
            }
        }
}
signed main() {
    memset(cable, -1, sizeof(cable));
    vector<int> squrt;
    for(int i = 0;i*i <= 1e7;i++) {
        squrt.push_back(i*i);
        for(int j:squrt) {
            if(i*i+j > 1e7) break;
            cable[i*i+j] = i;
        }
    }
    int n;
    cin >> n;
    while(n--) {
        solve();
    }
}

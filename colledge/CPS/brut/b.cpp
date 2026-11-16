#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = 0;
    for(int i = 0;i < 1000;i++) {
        string ss;
        int t = i;
        ss.push_back(t%10+'0');
        t/=10;
        ss.push_back(t%10+'0');
        t/=10;
        ss.push_back(t%10+'0');
        t/=10;
        int tg = 0;
        for(auto k:s) {
            if(k == ss[tg]) tg++;
            if(tg == 3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}

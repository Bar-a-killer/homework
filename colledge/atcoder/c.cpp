#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string ss;
    cin >> ss;
    int ans = 0;
    for(int i = 0;i < ss.length();i++) {
        if(ss[i] == 'C') {
            ans += min(i-0+1,(long long)ss.length()-i);
        }
    }
    cout << ans << endl;
}
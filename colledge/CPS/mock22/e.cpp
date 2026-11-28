#include <algorithm>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool dfs(vector<int> dt,int deep) {
    int cnt = 0;
    for(int i = 1;i < n;i++) {
        if(dt[i] != dt[i-1]+1) cnt++;
    }
    if(dt[0] != 1) cnt++;
    if(dt[n-1] != n) cnt++;
    if(cnt == 0) return 1;
    if(cnt > deep*3) return 0;
    for(int i = 0;i < n;i++) {
        for(int j = i+1;j<n;j++) {
            for(int k = j+1;k <= n;k++) {
                vector<int> a = dt;
                rotate(a.begin()+i, a.begin()+j, a.begin()+k);
                if(dfs(a,deep-1)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
signed main() {
    cin >> n;
    vector<int> dt(n);
    for(auto &i:dt) cin >> i;
    int i = 0;
    for(;;i++) {
        if(dfs(dt,i)) break;
    }
    cout << i << endl;
}

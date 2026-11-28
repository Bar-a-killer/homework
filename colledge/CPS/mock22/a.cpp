#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> leaf;
    int s=0,e;
    vector<int> deg(n+1,0);
    vector<pair<int,int>> ans;
    int ansint = 0;
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin >> tmp;
        if(tmp == 1) leaf.push_back(i);
        else {
            deg[i] = tmp;
            if(s == 0) {
                s = i;
            } else {
                ans.push_back({i,e});
                deg[i]--;
                deg[e]--;
                ansint++;
            }
            e = i;
        }
    } 
    if(s == 0) {
        cout << "NO" << endl;
        return 0;
    }
    if(!leaf.empty()) {
        ans.push_back({leaf.back(),s});
        leaf.pop_back();
        deg[s]--;
        ansint++;
    }
    
    if(!leaf.empty()) {
        ans.push_back({leaf.back(),e});
        leaf.pop_back();
        ansint++;
        deg[e]--;
    }
    int i = 1;
    while(!leaf.empty()) {
        while(i <= n && deg[i] == 0) i++;
        if(i > n) break;
        ans.push_back({i,leaf.back()});
        leaf.pop_back();
        deg[i]--;
    }
    if(!leaf.empty()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << " " << ansint << endl;
    cout << n-1 << endl;
    while(!ans.empty()) {
        cout << ans.back().first << " " << ans.back().second << '\n';
        ans.pop_back();
    }
}

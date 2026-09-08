#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> serv;
int k = 0;
int maxx = 0;
bool check(int n) {
    int tag = 0;
    int next = 0;
    int cnt = 0;
    while(next < serv.size()) {
        if(cnt >= k) return 0;
        if(serv[next] - serv[tag] > n) {
            cnt++;
            tag = next;
        }
        else next++;
    }
    return 1;
}
int bs(int l,int r) {
    int mid = (l+r)>>1;
    if(l >= r) return mid;
    if(check(mid)) {
        return bs(l,mid);
    } else {
        return bs(mid+1,r);
    }
}
signed main() {
    int n;
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        int tmp;cin >> tmp;
        serv.push_back(tmp);
        maxx = max(maxx,tmp);
    }
    sort(serv.begin(),serv.end());
    serv.erase(unique(serv.begin(), serv.end()), serv.end());
    cout << bs(0,maxx) << endl;
}
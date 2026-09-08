#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define f first
#define INF 1e18
#define s second
#define FOR(I,N) for(int I=0;I<(N);I++)
#define yuri ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    pii datas[n];
    FOR(i,n) {
        cin >> datas[i].s >> datas[i].f;
    }
    sort(datas,datas+n);
    int ans = 1;
    int i=1;
    int now_end = datas[0].f;
    while(i<n) {
        if(datas[i].s >= now_end) { // now_end > find_start
            ans++;
            now_end = datas[i].f;
        }
        i++;
    }
    cout << ans << endl;
}
signed main() {
    yuri;
    solve();
}
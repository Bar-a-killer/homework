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
    int ans = 0,tmp;
    priority_queue<int,vector<int>,greater<int>> q;
    FOR(i,n) {
        cin >> tmp;
        q.push(tmp);
    }
    while(q.size() > 1) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        ans += a+b;
        q.push(a+b);
    }
    cout << ans << endl;
}
signed main() {
    yuri;
    int t;
    cin >> t;
    while(t--)
        solve();
}
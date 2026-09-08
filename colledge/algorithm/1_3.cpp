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
int ans = 0;
void dc(vector<int>& datas,int left,int right) {
    int mid = (left+right)/2;
    if(left>=right) return;
    dc(datas,left,mid);
    dc(datas,mid+1,right);
    vector<int> templ(mid-left+1),tempr(right-mid);
    for(int i=0;i<templ.size();i++) {
        templ[i] = datas[left+i];
    }
    for(int i=0;i<tempr.size();i++) {
        tempr[i] = datas[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<templ.size() && j<tempr.size()) {
        if(templ[i] <= tempr[j]) {
            datas[k++] = tempr[j++];
        } else {
            datas[k++] = templ[i++];
            ans += (tempr.size()-j);
        }
    }
    while (i < templ.size()) datas[k++] = templ[i++];
    while (j < tempr.size()) datas[k++] = tempr[j++];
}
void solve() {
    int n;
    cin >> n;
    vector<int> datas(n);
    FOR(i,n) {
        cin >> datas[i];
    }
    dc(datas,0,n-1);
    cout << ans << endl;
}
signed main() {
    yuri;
    solve();
}
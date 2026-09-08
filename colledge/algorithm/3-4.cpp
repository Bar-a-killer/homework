#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define int long long

signed main() {
    int bf[1000][1000];
    int n;
    cin >> n;
    for(int i = 0;i < 1000;i++) {
        for(int j = 0;j < 1000;j++) {
            bf[i][j] = INF;
            if(i == j) bf[i][j] = 0;
        }
    }
    pair<int,int> metrix[505];
    for(int i = 0;i < n;i++) {
        int a,b;
        cin >> a >> b;
        metrix[i] = {a,b};
    }
    for(int k = 1;k <= n;k++) {
        for(int right = k;right < n;right++) {
            int left = right-k;
            for(int j = left;j <= right-1;j++) {
                bf[left][right] = min(bf[left][right],bf[left][j]+bf[j+1][right]+metrix[left].first*metrix[j].second*metrix[right].second);
            }
        }
    }
    // for(int i = 0;i < n;i++) {
    //     for(int j = 0;j < n;j++) {
    //         cout << bf[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << bf[0][n-1] << endl;
}
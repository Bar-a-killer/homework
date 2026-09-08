#include <bits/stdc++.h>
using namespace std;
#define int long long
 
// 暴力：枚舉答案從 1 開始，檢查能否用 K 次操作讓最大值 <= ans
bool ok(vector<int>& arr, int k, int mid) {
    if (mid <= 0) return false;
    long long ops = 0;
    for (int x : arr) {
        if (x > mid) {
            // ceil(x/mid) 個袋子，需要 ceil(x/mid)-1 次操作
            ops += (x + mid - 1) / mid - 1;
            if (ops > k) return false;
        }
    }
    return ops <= k;
}
 
signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
 
    for (int ans = 1; ; ans++) {
        if (ok(arr, k, ans)) {
            cout << ans << "\n";
            return 0;
        }
    }
}
 
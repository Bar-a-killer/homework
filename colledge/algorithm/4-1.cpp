#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
    int n,k;
    cin >> n >> k;

    vector<int> arr;
    for(int i = 0;i < n;i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    int l = 0;
    int r = arr.back();
    int bidx = arr.size()-1;
    while(l < r-1) {
        int mid = (l+r) >> 1;
        int step = k;
        for(int i = bidx;arr[i] > mid && i >= 0;i--) {
            step -= arr[i]%mid ? (arr[i]/mid) : (arr[i]/mid-1);
            if(step < 0) break;
        }
        if(step < 0) {
            l = mid;
            continue;
        } else {
            r = mid;
        }
    }
    cout << r << endl;
}
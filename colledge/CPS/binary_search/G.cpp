#include<bits/stdc++.h>
using namespace std;
#define int long long

bool equal(double a,double b) {
    if(a-b < 1e-6 && b-a < 1e-6) {
        return 1;
    } return 0;
}
signed main() {
    int n;cin >> n;
    int k;cin >> k;
    double l = 0.0,r = 1000.0;
    vector<int> datas;
    for(int i = 0;i < n;i++) {
        int tmp;cin >> tmp;
        datas.push_back(tmp);
    }
    while(!equal(l,r)) {
        double mid = (l+r)/2.0;
        double sum = 0,endsum = 0;
        double true_sum = 0;
        endsum = mid*n;
        for(int i:datas) {
            if(i > mid) {
                sum += i-mid;
                true_sum += mid;
            }
            else {
                true_sum += i;
            }
        }
        true_sum += sum*(100.0-k)/100.0;
        if(equal(true_sum,endsum)) {
            cout << fixed << setprecision(9) << mid << endl;
            return 0;
        } else if(true_sum > endsum){
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(9) << l << endl;
}

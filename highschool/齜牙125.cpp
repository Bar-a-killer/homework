#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int>& datas, int l, int r) {
    
    long long helf = (r + l) / 2;
    long long ans = 0;
    if (r - l == 2) {
		if (datas[l] > datas[r - 1]) {
			swap(datas[l],datas[r - 1]);
			return datas[l] + datas[r - 1];
		}
		else 
        	return 0;
    }
    if (r - l == 3) {
    	if (datas[l] > datas[r - 1]) {
			ans += datas[l] + datas[r - 1];
    		swap(datas[l],datas[r - 1]);
    	}
		if (datas[l] > datas[helf]) {
			ans += datas[l] + datas[helf];
			swap(datas[l],datas[helf]);
		}
		if (datas[helf] > datas[r - 1]) {
			ans += datas[r - 1] + datas[helf];
			swap(datas[r - 1],datas[helf]);
		}
		return ans;
    }
    
    ans += solve(datas, l, helf) + solve(datas, helf, r);
    
    for (int i = l; i < helf; i++) {
        for (int j = helf; j < r; j++) {
            if (datas[i] > datas[j]) {
                ans += datas[i] + datas[j];
            	cout << datas[i] << ": " << datas[j] << ",";
            	swap(datas[i],datas[j]);
            }
        }
    }
    
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> datas(N+1);
    for (int i = 1; i < N+1; i++)
        cin >> datas[i];
    cout << solve(datas, 1, N+1) % 10000019 << endl;
    return 0;
}
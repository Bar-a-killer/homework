#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	long long n,Q;
	long long l,r,k;
	
	cin >> n >> Q;
	
	vector<long long> people(n);
    for(int i = 0; i < n; i++) {
        cin >> people[i];
    }
	long long ans = 0;
	long long k2;
	while(Q--) {
		cin >> l >> r >> k;
		l -= 1;
		r -= 1;
		k2 = 2*k;
		while(l<=r) {
			if(k>people[l])
				ans += k2;
			else if(k<people[l])
				ans += people[l]*2;
			l++;
		}
		cout << ans << endl;
		ans = 0;
	}
}
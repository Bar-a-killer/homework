#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin >> T;
	int mat[4] = {2,3,5,7};
	int mah[2] = {4,6};
	while(T--) {
		deque<int> output;
		long long n;
		long long eight=0;
		cin >> n;
		if(n == 1) {
			cout << 1 << endl;
			continue;
		}
		while(n%8==0) {
			n = n/8;
			eight++;
		}
		for(int i = 0;i<2;i++) {
			while(n%mah[i] == 0) {
				n/=mah[i];
				output.push_back(mah[i]);
			}
		}
		while(eight--) 
			output.push_back(8);
		while(n%9 == 0) {
			n/=9;
			output.push_back(9);
		}
		for(int i = 3;i>=0;i--) {
			while(n%mat[i] == 0) {
				n/=mat[i];
				output.push_front(mat[i]);
			}
		}
		if(n == 1) {
			for(int i:output) {
				cout << i;
			}
		}
		else
			cout << -1;
		cout << endl;
	}
}
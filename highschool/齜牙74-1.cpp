#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		long long n,fir,sec;
		cin >> n;
		cin >> fir;
		bool det = true;
		long long total = 0;
		n--;
		while(n--) {
			cin >> sec;
			if((sec < fir) == det && sec != fir) {
				det = !det;
				total++;
			}
			fir = sec;
		}
		if(det) {
			total++;
		}
		cout << total << endl;
	}
}
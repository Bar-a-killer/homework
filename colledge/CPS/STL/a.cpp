#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	string s;
	cin >> s;
	int allupper = 1;
	int first = 0;
	for(char c:s) {
		if(!first) {
			first = 1;
		       	continue;
		}
		if(!isupper(c)) {
			allupper = 0;	
		}
	}
	if(allupper) {
		for(char c:s) {
			cout << char(isupper(c)?tolower(c):toupper(c));
		}
	}
	else cout << s;
	cout << endl;
}

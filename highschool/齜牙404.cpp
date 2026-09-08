#include <bits/stdc++.h>
using namespace std;

int mod = 1000007;
<<<<<<< HEAD
int c = 10;

int main() {
    int a;
    cin >> a;
    string str;
    cin >> str;
    vector<int> hash(a + 1);
    vector<long long> tws(a + 1);
    
    hash[0] = str[0] - 'a' + 1;
    tws[0] = 1;
    for (int i = 1; i < a; i++) {
        tws[i] = (tws[i-1] * c) % mod;
        hash[i] = (hash[i-1] + (str[i]-'a' + 1) * tws[i]) % mod;
        cout << i << ":" << hash[i] << endl;
    }
    int ans = 0;
    for (int i = 2; i < a; i++) {
        for (int j = i-1; j >= 1; j--) {
        	cout << i << ":" << (hash[j-1] + (hash[j-1] * tws[j] % mod)) % mod << endl;
            if ((hash[j-1] + (hash[j-1] * tws[j] % mod) - hash[i] + tws[i]) % tws[i] == 0) {
                ans += j;
                cout << i << " " << j << endl;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
=======
int k = 10;
int main() {
	int a;
	cin >> a;
	string str;
	cin >> str;
	vector<int> hash(a);
	vector<long long> tws(a);
	long long r = 1;
	hash[0] = str[0] - 'a' +1;
	tws[0] = 1;
	for (int i = 1; i <= a; i++) {
	    tws[i] = (r * tws[i-1] * k) % mod;
	    hash[i] = (r * hash[i-1] + (str[i] - 'a' + 1) * tws[i]) % mod;
	    hash[i] = (hash[i] + mod) % mod;
	    cout << i << ":" << hash[i] << endl;
	}
	int ans = 0;
	
	for(int i = 1;i <= a ; i++) {
		for(int j = i-1;j >= i/2;j--) {
//			cout << i << " " << j << ":" << endl;
//			cout << (hash[j] + hash[j] * tws[j+1] % mod) % mod << "\n" << hash[i] << "\n" << hash[j] + hash[j] * tws[j+1] % mod - hash[i] << endl;
			if(((hash[j] + hash[j] * tws[j+1] % mod) % mod - hash[i]) % tws[i] == 0) {
				ans += j;
				
				break;
			}
		}
	}
	cout << ans << endl;
>>>>>>> 6e20495ffbf3827d02b216d64c94e45da0547bbf
}
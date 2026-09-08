#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	priority_queue<int,vector<int>,greater<int>> pq;
	int n,mod,num;
	cin >> n;
	while(n--) {
		cin >> mod;
		if(mod == 1) {
			cin >> num;
			pq.push(num);
		}
		else if(pq.empty())
			cout << "empty!" << endl;
		else {
			cout << pq.top() << endl;
			pq.pop(); 
		}
			
	}
}
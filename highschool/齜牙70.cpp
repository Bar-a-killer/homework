#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  long long tmp;
  cin >> T;
  while(T--) {
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    long long ans = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
      cin >> tmp;
      minHeap.push(tmp);
    }
    while(minHeap.size() != 1) {
      tmp = 0;
      tmp += minHeap.top();
      minHeap.pop();
      tmp += minHeap.top();
      minHeap.pop();
      ans += tmp;
      minHeap.push(tmp);
    }
    cout << ans << endl;
    minHeap.pop();
  }
}

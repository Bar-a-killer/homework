#include<bits/stdc++.h>
using namespace std;
#define For(i,x) for(int i = 0;i < x ; i++)

struct node {
	int father = 0;
	bool exist = 1;
	vector<int> children;
};
int main() {
	int T;
	cin >> T;
	while(T--) {
		int n,m;
		int p1,p2;
		vector<node> graph;
		cin >> n >> m;
		graph.resize(n);
		For(i,m) {
			cin >> p1 >> p2;
			graph[p1].children.push_back(p2);
			graph[p2].father++;
		}
		queue<int> output;
		priority_queue<int, vector<int>, greater<int> > lone;
		for(int i = 0; i<n ; i++) {
			if(graph[i].exist && graph[i].father == 0) {
				lone.push(i);
				graph[i].exist = 0;
			}
		}
		int ttop;
		while(!lone.empty()) {
			ttop = lone.top();
			lone.pop();
			for(int i : graph[ttop].children)
				if(graph[i].exist) {
					if(--graph[i].father == 0) {
						graph[i].exist = 0;
						lone.push(i);
					}
				}
			output.push(ttop);
			//cout << ttop << endl;
		}
		bool go = 0;
		For(j,n) {
			if(graph[j].exist)
				go = 1;
		}
		if(go)
			cout << "QAQ" << endl;
		else {
			while(output.size() > 1) {
				cout << output.front() << " ";
				output.pop();
			}
			cout << output.front() << endl;
			output.pop();
		}
	}
}
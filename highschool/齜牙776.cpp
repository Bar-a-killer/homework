#include<bits/stdc++.h>
using namespace std;
#define ll long long

int ccount[100] = {0};
int llist[100][100];
int run(int s, ll L, ll N) {
    std::vector<int> ccount(N, 0);  // 存储结果的数组，初始化为0
    ccount[s]++;  // 初始状态计数加1

    for (ll step = 1; step <= L; step++) {
        std::vector<int> next_count(N, 0);  // 存储下一步计数的临时数组

        for (int i = 0; i < N; i++) {
            if (ccount[i] > 0) {
                for (int j = 0; j < N; j++) {
                    if (llist[i][j] == 1) {
                        next_count[j] += ccount[i];
                    }
                }
            }
        }

        ccount = next_count;  // 更新计数数组
    }

    return 0;
}
int main() {
	ll N,M,L;
	cin >> N >> M >> L;
	
	int X,Y;
	for(int i = 0 ; i < M ; i++ ) {
		cin >> X >> Y;
		llist[X-1][Y-1] = 1;
	}
	for(int i = 0; i < N ; i++) {
		run(i,L,N);
		for(int j=0;j<N-1;j++) {
			cout << ccount[j] << " ";
			ccount[j] = 0;
		}
		cout << ccount[N-1] << endl;
		ccount[N-1] = 0;
	}
}
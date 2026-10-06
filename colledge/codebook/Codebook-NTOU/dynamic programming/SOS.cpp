// 求子集和 或超集和 -> !(mask & (1 << i))
for(int i = 0; i<(1<<N); ++i)	F[i] = A[i]; //預處理 狀態權重

for(int i = 0;i < N; ++i)
for (int s = 0; s < (1<<N) ; ++s)
	if (s & (1 << i))
		F[s] += F[s ^ (1 << i)];

//窮舉子集合
for(int s = mask; s ; s = (s-1)&mask;)
//放這個做啥我不會用QAQ
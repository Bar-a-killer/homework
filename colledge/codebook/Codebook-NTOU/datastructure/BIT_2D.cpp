struct BIT {
  int n;
  vector<vector<ll>> bit;
  int lowbit(int x) { return x & -x; }
  BIT(int _n) : n(_n + 1) {
    bit.assign(n, vector<ll>(n, 0));
  }
  void update(int x, int y, ll val) {  // 更新 (x, y)
    for (int i = x; i < n; i += lowbit(i))
      for (int j = y; j < n; j += lowbit(j))
        bit[i][j] += val;
  }
  ll query(int x, int y) {  // 查詢 (1, 1) ~ (x, y) 的和
    ll ans = 0;
    for (int i = x; i; i -= lowbit(i))
      for (int j = y; j; j -= lowbit(j)) ans += bit[i][j];
    return ans;
  }
  ll range_query(int a, int b, int x, int y) {
    return query(x, y) - query(x, b - 1) -
           query(a - 1, y) + query(a - 1, b - 1);
  }
};
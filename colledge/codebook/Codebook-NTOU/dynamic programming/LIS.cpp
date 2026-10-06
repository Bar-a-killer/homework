#define all(v) (v).begin(), (v).end()

vector<int> dp;
for(int i = 0; i < n;++i){
    auto it = lower_bound(all(dp),A[i]);
    if(it == dp.end()){
        dp.push_back(A[i]);
    }else{
        *it = A[i];
    }
}
cout << dp.size() << '\n';
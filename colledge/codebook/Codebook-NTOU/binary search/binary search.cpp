int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
// ................oooooooooo
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
// ooooooooo...................
int m = *ranges::partition_point(views::iota(0LL,(int)1e9+9),[&](int a){
		return check(a) > k;
    });
//[begin,last)
//111111100000000000
//搜左邊數過來第一個 0
//都是 1 會回傳 last
int partitionpoint(int L,int R,function<bool(int)> chk){
	int l = L,r = R-1;
	while(r - l > 10){
		int m = l + (r-l)/2;
		if(chk(m)) l = m;
		else r = m;
	}
    int m = l;
    while(m <= r){
        if(!chk(m)) break;
        ++m;
    } 
	if(!chk(m)) return m;
	else return R;
}
//手工
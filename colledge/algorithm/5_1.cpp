#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,m;
    cin >> n >> m;
    vector<int> grap[n+1];
    bool vis[n+1] = {0};
    int color[n+1];
    while(m--) {
        int a,b;
        cin >> a >> b;
        grap[a].push_back(b);
        grap[b].push_back(a);
    }
    stack<int> st;
    for(int i = 0;i < n;i++) {
        if(!vis[i]) {
            vis[i] = 1;
            color[i] = 0;
            st.push(i);
            while(!st.empty()) {
                int now = st.top();st.pop();
                for(int chil:grap[now]) {
                    if(vis[chil] && color[chil] == color[now]) {
                        cout << "Bruh" << endl;
                        return 0;
                    }
                    if(!vis[chil]) {
                        vis[chil] = true;
                        color[chil] = !color[now];
                        st.push(chil);
                    }
                }
            }
        }
    }
    cout << "Yappeee" << endl;
}
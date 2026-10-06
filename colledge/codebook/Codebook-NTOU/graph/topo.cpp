vector<int> edge[MAXN], ans;  
int deg[MAXN];      

void topo(int n) {  
    queue<int> q; 
    
    for (int i = 1; i <= n; i++)
        if (!deg[i]) 
            q.push(i);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u); 
        
        for (int v : edge[u]) {
            deg[v]--; 
            if (!deg[v]) 
                q.push(v);
        }
    }
}
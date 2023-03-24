void bfs(int n, vector<int>adj[]) {
    vector<bool>visited(n,false);
    queue<int>q;
    q.push(0);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        visited[node] = true;
        for(auto x : adj[node]) {
            if(!visited[x])
            {
                cout<<x<<" ";
                visited[x]=true;
            }
        }
    }
    cout<<endl;
}
int main() {
    int n = 6;
    vector<vector<int>>G = {{0,1},{0,2},{0,3},{1,2},{4,5}};
    vector<int>adj[n];
    for(auto x : G) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    bfs(n,adj);
}

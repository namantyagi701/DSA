// Breadth First Search (BFS)
// Time Complexity: O(V + E)
// Space Complexity: O(V)

vector<int> bfs(vector<vector<int>> &adj , int n){

    queue<int>q;
    vector<int>vis(n+1 ,0);
    vector<int> ls;
    
    q.push(1);
    vis[1] = 1;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ls.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ls;
}
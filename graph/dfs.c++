// Depth First Search (Recursive)
// Time Complexity: O(V + E)
// Space Complexity: O(V)

void dfs(const vector<vector<int>> &adj, vector<int> &vis,int node, vector<int> &result) {

    vis[node] = 1;
    result.push_back(node);

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(adj, vis, neighbor, result);
        }
    }
}

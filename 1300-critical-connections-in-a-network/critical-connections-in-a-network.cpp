class Solution {
private:
    int timer = 1;

public:
    void dfs(int node, int parent, vector<int>& low, vector<int>& tin, vector<int>& vis,
             vector<vector<int>>& adj, vector<vector<int>>& ans) {
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        for (auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it , node , low , tin , vis , adj , ans);
                low[node] = min(low[node] , low[it]);
                if(low[it] > tin[node]) {
                    ans.push_back({it , node});
                }
            }
            else
            low[node] = min(low[node] , tin[it]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < arr.size(); i++) {
            int u = arr[i][0];
            int v = arr[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> vis(n, 0);
        vector<vector<int>> ans;
        dfs(0, -1 , low, tin, vis, adj, ans);
        return ans;
    }
};
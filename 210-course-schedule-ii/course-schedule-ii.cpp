class Solution {
public:
    bool cycle(int node, vector<int>& vis, vector<int>& path,
               vector<vector<int>>& adj) {
                 vis[node] = 1;
                 path[node] = 1;

                 for(auto it: adj[node]){
                    if(!vis[it]){
                        if(cycle(it , vis , path , adj)) return true;
                    }
                    else{
                        if(path[it] == 1) return true;
                    }
                 }
                 path[node] = 0;
                 return false;
               }

    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj,
             stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    vector<int> findOrder(int V, vector<vector<int>>& arr) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < arr.size(); i++) {
            int u = arr[i][0];
            int v = arr[i][1];
            adj[v].push_back(u);
        }

        vector<int> visit(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visit[i]) {
                if (cycle(i, visit, pathVis, adj)) {
                    return {};
                }
            }
        }

        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
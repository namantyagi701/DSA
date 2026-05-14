class Solution {
public:
    void dfs(int i , vector<int> &vis , vector<vector<int>> &adj){
        vis[i] = 1;

        for(auto it: adj[i]){
            if(!vis[it])
            dfs(it , vis , adj);
        }
    }

    int findCircleNum(vector<vector<int>>& arr) {
        int nos = 0;
        int n = arr.size();
        vector<int>vis(n , 0);

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && arr[i][j] == 1)
                    adj[i].push_back(j);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                nos++;
                dfs(i, vis, adj);
            }
        }
        return nos;
    }
};
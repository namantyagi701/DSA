class Solution {
public:
    void dfs(int node , vector<vector<int>> &adj , vector<int>& vis){
        vis[node] = 1;
        for(int i = 0 ; i < adj[node].size() ; i++){
            if(!vis[adj[node][i]])
            dfs(adj[node][i] , adj , vis);
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(arr[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n , 0);
        int cnt = 0;
        for(int i = 0 ; i < adj.size() ; i++){
            if(vis[i] != 1){
                cnt++;
                dfs(i , adj , vis);
            }
        }
        return cnt;
    }
};
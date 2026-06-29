class Solution {
public:
    void dfs(int node , vector<vector<int>> &arr , vector<int> &vis){
        vis[node] = 1;
        for(auto it: arr[node]){
            if(!vis[it]){
                dfs(it , arr , vis);
            }
        }
    }
    int number(vector<vector<int>> &vect){
        int n = vect.size();
        int count = 0;
        vector<int>vis(n , 0);
            for(int i = 0 ; i < n ; i++){
                if(!vis[i]){
                    count++;
                    dfs(i , vect , vis);
                }
            }

        return count;
    }
    int makeConnected(int n, vector<vector<int>>& arr) {
        if(arr.size() < n - 1) return -1;
        vector<vector<int>>vect(n);
        for(int i = 0 ; i < arr.size() ; i++){
            int u = arr[i][0];
            int v = arr[i][1];
            vect[u].push_back(v);
            vect[v].push_back(u);
        }
        int nos = number(vect);
        return nos-1;
    }
};
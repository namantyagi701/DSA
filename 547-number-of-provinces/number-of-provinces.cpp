class Solution {
public:
    void dfs(int node , vector<vector<int>> &arr , vector<int>& vis){
        vis[node] = 1;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[node][i] == 1 && !vis[i] && node != i)
               dfs(i , arr , vis);
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int>vis(n , 0);
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(vis[i] != 1){
                cnt++;
                dfs(i , arr , vis);
            }
        }
        return cnt;
    }
};
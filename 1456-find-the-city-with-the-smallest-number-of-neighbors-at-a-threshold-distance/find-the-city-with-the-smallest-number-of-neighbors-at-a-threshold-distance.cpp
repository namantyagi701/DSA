class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>>mat(n , vector<int>(n , 1e8));
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            mat[u][v] = w;
            mat[v][u] = w;
        }
        vector<int>count(n , 0);
        for(int via = 0 ; via < n ; via++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(mat[i][via] != 1e8 && mat[via][j] != 1e8){
                        mat[i][j] = min(mat[i][j] , mat[i][via] + mat[via][j]);
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i++) mat[i][i] = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] <= d){
                    count[i]++;
                }
            }
        }
        int min_count = 1e9;
        int ans = 0;
        for(int i = 0 ; i < count.size() ; i++){
            if(count[i] <= min_count){
                ans = i;
                min_count = count[i];
            }
        }
        return ans;
    }
};
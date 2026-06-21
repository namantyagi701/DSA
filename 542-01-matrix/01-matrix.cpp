class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n , vector<int>(m , 0));
        vector<vector<int>> vis(n , vector<int>(m , 0));
        queue<pair<int , pair<int , int>>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j =  0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({0,{i,j}});

                }
            }
        }  
        int dx[] ={0 , 1 , 0 , -1};
        int dy[] ={1 , 0 , -1 , 0};
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int cnt = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;
            for(int i = 0 ; i < 4 ; i++){
                int nRow = row + dx[i];
                int nCol = col + dy[i];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && mat[nRow][nCol] != 0 && vis[nRow][nCol] != 1){
                    vis[nRow][nCol] = 1;
                    ans[nRow][nCol] = cnt + 1;
                    q.push({cnt+1 , {nRow , nCol}});
                }
            }
        } 
        return ans;     
    }
};
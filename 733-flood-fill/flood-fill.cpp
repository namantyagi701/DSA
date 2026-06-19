class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c = image[sr][sc];
        if(c == color) return image;
        int n = image.size();
        int m = image[0].size();
        // vector<vector<int>> arr(n , vector<int>(m , 0));
 
        queue<pair<int,int>>q;
        q.push({sr , sc});
        image[sr][sc] = color;
        int dx[] ={-1 , 0 , 1, 0};
        int dy[] ={0 , 1 , 0 , -1};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;
            for(int i = 0 ; i < 4 ; i++){
                int nRow = row + dx[i];
                int nCol = col + dy[i];
                if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0 && image[nRow][nCol] == c){
                    image[nRow][nCol] = color;
                    q.push({nRow , nCol});
                }
            }
        }
        return image;
    }
};
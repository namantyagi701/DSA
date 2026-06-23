class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        set < pair<int, pair<int, int>>> st;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        st.insert({0, {0, 0}});
        dist[0][0] = 0;
        int dx[] = {-1, 1, 0, 0}; 
        int dy[] = {0, 0, -1, 1};
        while (!st.empty()) {
            auto ele = *st.begin();
            st.erase(st.begin());
            int val = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;
            if(row == n-1 && col == m-1) return val;
            for(int i = 0 ; i < 4 ; i++){
                int nRow = row + dx[i];
                int nCol = col + dy[i];
                if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0){
                    int diff = max(abs(arr[row][col] - arr[nRow][nCol]) , val);
                    if(dist[nRow][nCol] > diff){
                        dist[nRow][nCol] = diff;
                        st.insert({diff , {nRow , nCol}});
                    }
                }
            }
        }
        return 0;
    }
};
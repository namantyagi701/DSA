class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1, 0));

        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= m - k; j++) {

                set<int> st;            
                int minDiff = INT_MAX;        

             
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {

                        auto it = st.insert(grid[r][c]).first;

                       
                        if (it != st.begin()) {
                            auto prevIt = prev(it);
                            minDiff = min(minDiff, abs(*it - *prevIt));
                        }

                  
                        auto nextIt = next(it);
                        if (nextIt != st.end()) {
                            minDiff = min(minDiff, abs(*it - *nextIt));
                        }
                    }
                }

  
                if (minDiff == INT_MAX) minDiff = 0;

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};
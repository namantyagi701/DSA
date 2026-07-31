class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        set<int>st;
        int n = grid.size();
        int r = 0;
        int m = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(st.find(grid[i][j]) != st.end()){
                    r = grid[i][j];
                }
                st.insert(grid[i][j]);
            }
        }
        int i = 1;
        while(!st.empty()){
           int front = *(st.begin());
           st.erase(st.begin());
           if(i != front){
            m = i;
            break;
           }
           i++;
        }
        if(m == 0) m = i;
        return {r , m};
    }
};
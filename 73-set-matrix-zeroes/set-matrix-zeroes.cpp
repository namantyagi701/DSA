class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<pair<int , int>>vect;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(arr[i][j] == 0){
                    vect.push_back({i , j});
                } 
            }
        }
        for(int i = 0 ; i < vect.size() ; i++){
            int row = vect[i].first;
            int col = vect[i].second;
            for(int j = 0 ; j < m ; j++){
                arr[row][j] = 0;
            }
            for(int j = 0 ; j < n ; j++){
                arr[j][col]  = 0;
            }
        }
    }
};
class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int ans = INT_MAX;
        for(int i = 0 ; i < ls.size() ; i++){
            int first = ls[i] + ld[i];
            for(int j = 0 ; j < ws.size() ; j++){
               if(first >= ws[j]){
                  ans = min(ans , first + wd[j]);
               }
               else{
                int arrear = ws[j] - first;
                ans = min(ans , first + arrear + wd[j]);
               }
            }
        }
        for(int i = 0 ; i < ws.size() ; i++){
            int first = ws[i] + wd[i];
            for(int j = 0 ; j < ls.size() ; j++){
                if(first >= ls[j]){
                    ans = min(ans , first + ld[j]);
                }
                else{
                int arrear = ls[j] - first;
                ans = min(ans , first + arrear + ld[j]);
               }
            }
        }
        return ans;
    }
};
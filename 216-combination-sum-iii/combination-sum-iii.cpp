class Solution {
public:
    void f(int idx , vector<int> &temp , vector<vector<int>> &ans, int k , int n){
        if(k == 0 && n == 0){
            ans.push_back(temp);
        } 
        if(n < 0 || k < 0) return;

        for(int i = idx ; i <= 9 ; i++){
            if(i > k) break;
            
            
            temp.push_back(i);

            f(i+1 , temp ,ans , k-i , n-1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        f(1 ,temp , ans, n, k);
        return ans;
    }
};
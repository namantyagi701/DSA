class Solution {
public:
    void check(int i ,vector<vector<string>> &ans , vector<string> &ds , string s){
        if(i == s.size()){
          ans.push_back(ds);
          return;
        }
        for(int j = i ; j < s.size() ; j++){
            if(isPalindrome(i , j,s)){
                ds.push_back(s.substr(i , j - i + 1));
                check(j + 1 , ans , ds , s);
                ds.pop_back();
            }
        }        
    }
    bool isPalindrome(int i , int j , string s){
        
        while(i <= j) {
            if(s[i] != s[j])
            return false;
            i++;
            j--;
        }
        return true;
     }

    vector<vector<string>> partition(string s) {
       vector<vector<string>>ans;
       vector<string>ds;
       check(0 , ans , ds , s);
       return ans; 
    }
};
class Solution {
public:
    void f(int open , int close , string &s , vector<string>&ans){
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }

        if(open > 0){
            s += "(";
            f(open -1 , close , s , ans);
            s.pop_back();
        }
        if(close > open){
            s += ")";
            f(open , close -1 , s , ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string>ans;
        f(n , n , s , ans);

        return ans;
    }
};
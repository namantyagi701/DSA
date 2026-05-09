class Solution {
public:
    void f(int idx , string digits , vector<string> &vect , vector<string>&ans , string &temp){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }
        string s = vect[digits[idx] - '0' - 1];
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            temp += s[i];
            f(idx + 1 , digits , vect , ans , temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       vector<string>vect;
       vect.push_back("");
       vect.push_back("abc");
       vect.push_back("def");
       vect.push_back("ghi");
       vect.push_back("jkl");
       vect.push_back("mno");
       vect.push_back("pqrs");
       vect.push_back("tuv");
       vect.push_back("wxyz");
       string temp; 
       vector<string>ans;
       f(0 , digits , vect , ans , temp);
       return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return strs[0];
        string common = "";
        string s1 = strs[0];
        string s = strs[1];
        for(int j = 0 ; j < min(s1.size() , s.size()) ; j++){
                if(s1[j] != s[j]) break;
                common += s1[j];
            } 
        string nc = "";
        for(int i = 1 ; i < n ; i++){
            string s2 = strs[i];
            for(int j = 0 ; j < min(common.size() , s2.size()) ; j++){
                if(s2[j] != common[j]) break;
                nc += s2[j];
            }         
            common = nc;
            nc = "";
        }
        return common;
    }
};
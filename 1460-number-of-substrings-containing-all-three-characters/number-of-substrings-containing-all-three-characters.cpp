class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>ls(3 , -1);
        int cnt = 0;
        for(int i = 0 ; i < s.size() ; i++){
            ls[s[i] - 'a'] = i;
            
            cnt += 1 + min({ls[0] , ls[1] , ls[2]});
        }
        return cnt;
    }
};
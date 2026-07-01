class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m) return false;
        sort(s.begin() , s.end());
        sort(t.begin(), t.end());
        int i ;
        for(i = 0 ; i < min(n , m) ; i++){
            if(s[i] != t[i]) return false;
        } 
        if(i < n || i < m) return false;
        return true;
    }
};
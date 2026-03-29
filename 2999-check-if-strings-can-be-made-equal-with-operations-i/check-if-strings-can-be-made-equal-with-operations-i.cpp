class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<string>st;
        string t = s1;
        if(s1 == s2) return true;
        swap(s1[0] , s1[2]);
        st.push_back(s1);
        swap(s1[1] , s1[3]);
        st.push_back(s1);
        swap(t[1] , t[3]);
        st.push_back(t);

        for(int i = 0 ; i < st.size() ; i++){
            if(s2 == st[i]) return true;
        }
        return false;
    }
};
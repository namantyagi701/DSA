class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0 || s[0] == ')' || s[0] == ']' || s[0] == '}')
            return false;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;
                if (st.top() == '[' && s[i] == ']' ||
                    st.top() == '(' && s[i] == ')' ||
                    st.top() == '{' && s[i] == '}') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};
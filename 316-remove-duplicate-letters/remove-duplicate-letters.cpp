class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, -1);
        vector<bool> vis(26, false);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        string st;
        int i = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            if (vis[s[i] - 'a'] == true)
                continue;
            while (!st.empty() && st.back() > s[i] && last[st.back() - 'a'] > i) {
                vis[st.back() - 'a'] = false; 
                st.pop_back();
            }
            st.push_back(s[i]);
            vis[s[i] - 'a'] = true;
        }
        return st;
    }
};
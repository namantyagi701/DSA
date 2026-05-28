class Solution {
public:
    string reverseWords(string s) {
        string temp = "";

        int start = 0;
        int end = s.size() -1;

        while (start < s.size() && s[start] == ' ')
            start++;

        while (end >= 0 && s[end] == ' ')
            end--;

        stack<string>st;
        for(int i = start ; i <= end ; i++){
            if(temp == "" && s[i] == ' ') continue;
            if(s[i] == ' '){
                st.push(temp);
                temp = "";
            }
            else
            temp += s[i];
        }
        st.push(temp);
        string ans = "";
        while(!st.empty()){
            string word = st.top();
            ans += word + " ";
            st.pop();
        }
        string res = ans.substr(0, ans.size() - 1);
        return res;
    }
};
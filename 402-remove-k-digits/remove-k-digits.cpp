class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k)
            return "0";

        int count = 0;
        stack<char> st;
        for (int i = 0; i < num.length(); i++) {
            while (!st.empty() && st.top() > num[i] && count != k) {
                st.pop();
                count++;
            }
            st.push(num[i]);
        }
        if (count < k) {
            for (int i = 0; i < k - count; i++) {
                st.pop();
            }
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        int i = 0;
        while (i < result.length() && result[i] == '0') {
            i++;
        }
        result = result.substr(i);

        if (result == "") return "0";
        return result;

    }
};
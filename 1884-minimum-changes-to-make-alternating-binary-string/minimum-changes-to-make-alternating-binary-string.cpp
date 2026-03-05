class Solution {
public:
    int minOperations(string s) {
        string t = "";
        string t2 = "";
        t += '0';
        t2 += '1';

        for (int i = 1; i < s.size(); i++) {
            if ((t[i - 1] - '0') == 0)
                t += '1';
            else
                t += '0';
        }

        for (int i = 1; i < s.size(); i++) {
            if ((t2[i - 1] - '0') == 0)
                t2 += '1';
            else
                t2 += '0';
        }
        int cnt = 0;
        int cnt2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                cnt++;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t2[i]) {
                cnt2++;
            }
        }
        return min(cnt,cnt2);
    }
};
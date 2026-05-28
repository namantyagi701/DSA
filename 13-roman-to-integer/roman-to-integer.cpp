class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanmap;
        romanmap['I'] = 1;
        romanmap['V'] = 5;
        romanmap['X'] = 10;
        romanmap['L'] = 50;
        romanmap['C'] = 100;
        romanmap['D'] = 500;
        romanmap['M'] = 1000;
        int sum = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int curr = romanmap[s[i]];
            if (i == s.size() - 1) {
                sum += curr;
            } else {
                if (curr == 1 && ( s[i + 1] == 'V' || s[i+1] == 'X')) {
                    sum -= curr;
                } else if (curr == 10 && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    sum -= curr;
                } else if (curr == 100 && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    sum -= curr;
                } else {
                    sum += curr;
                }
            }
        }
        return sum;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> arr(3, -1);
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a'] = i;
            if (arr[0] != -1 && arr[1] != -1 && arr[2] != -1) {
                count = count + (1 + min({arr[0], arr[1], arr[2]}));
            }
        }
        return count;
    }
};
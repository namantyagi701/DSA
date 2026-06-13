class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        string temp = "abcdefghijklmnopqrstuvwxyz";
        for(int i = 0 ; i < words.size() ; i++){
            int sum = 0;
            for(int j = 0 ; j < words[i].size() ; j++){
                int idx = words[i][j] - 'a';
                sum += weights[idx];
            }
            int mod = sum % 26;
            ans += temp[temp.length()- 1 - mod];                     
        }
        return ans;
    }
};
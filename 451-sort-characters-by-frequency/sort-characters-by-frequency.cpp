class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<vector<char>> bucket(n + 1);
        unordered_map<char,int>mpp;
        for(int i = 0 ; i < s.size() ; i++){
            mpp[s[i]]++;
        }
  
        for(auto it: mpp){
            char ch = it.first;
            int freq = it.second;
            bucket[freq].push_back(ch);
        }   
        string ans = "";
        for(int i = n ; i >= 0 ; i--){
           for(int j = 0 ; j < bucket[i].size() ; j++){
            ans += string(i , bucket[i][j]);
           }
        }
        return ans;
    }
};
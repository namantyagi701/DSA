class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char , int>mpp;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            mpp[s[i]] = i;
        }
        int end = 0;
        int cnt = 0;
        vector<int>ans;
        int start = 0;
        for(int i = 0 ; i < n ; i++){
            end = max(end , mpp[s[i]]);

            if(i == end){
                cnt = i - start + 1;
                ans.push_back(cnt);
                start = i + 1;
            }
        }
        return ans;
    }
};
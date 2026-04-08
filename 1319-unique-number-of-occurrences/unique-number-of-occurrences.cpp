class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> mpp;
        for(auto it: arr){
            mpp[it]++;
        }
        unordered_set<int>st;
        for(auto it : mpp){
            int x = it.second;
            if(st.find(x) != st.end()) return false;
            else st.insert(x);
        }
        return true;
    }
};
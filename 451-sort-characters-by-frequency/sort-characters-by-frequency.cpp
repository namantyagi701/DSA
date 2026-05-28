class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(int i = 0 ; i < s.size() ; i++){
            mpp[s[i]]++;
        }
        vector<pair<int , char>> arr;
        for(auto it: mpp){
            char ch = it.first;
            int freq = it.second;
            arr.push_back({freq, ch});
        }   
        sort(arr.begin() , arr.end() , greater<pair<int,char>>()); 
        s = "";    
        for(int i = 0 ; i < arr.size() ; i++){
            int freq = arr[i].first;
            char ch = arr[i].second;
            for(int j = 0 ; j < freq ; j++){
                s += ch;
            }
        }
        return s;
    }
};
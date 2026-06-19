class Solution {
public:
    static bool comp(const string& a, const string& b) {
        if (a.size() == b.size())
        return a < b;
        return a.size() < b.size();
    }

    string longestWord(vector<string>& words) {
        int n = words.size();
        unordered_set<string>st;
        int size = 1;
        sort(words.begin() , words.end() , comp);
        if(words[0].size() != 1) return "";
        for(int i = 0 ; i < n ; i++){
            if(words[i].size() == 1) st.insert(words[i]);
            else{
                string word = words[i];
                string curr = word.substr(0 , word.size() -1);
                if(st.find(curr) != st.end()){
                    st.insert(word);
                }
            }
        }
        vector<string>arr(st.begin() , st.end());
        sort(arr.begin() ,arr.end() , comp);
        int sizee = arr.size();
        int maxi = arr[sizee -1].size();
        int i = arr.size()-1;
        while(i >= 0 && arr[i].size() >= maxi){
            i--;
        }     
        return arr[i+1];
    }
};
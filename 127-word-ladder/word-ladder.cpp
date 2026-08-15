class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(int i = 0 ; i < wordList.size() ; i++){
            st.insert(wordList[i]);
        }
        queue<pair<string,int>>q;
        q.push({beginWord , 1});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            string s = curr.first;
            int no = curr.second;
            if(s == endWord) return no;
            for(int i = 0 ; i < s.size() ; i++){
                char org = s[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    s[i] = ch;
                    if(st.count(s)) q.push({s , no + 1});
                    st.erase(s);
                }
                s[i] = org;
            }
        }
        return 0;
    }
};
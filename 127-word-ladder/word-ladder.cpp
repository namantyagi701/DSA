class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int,string>>q;
        q.push({1 , beginWord});
        set<string>st;
        for(auto it: wordList){
            st.insert(it);
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int cnt = curr.first;
            string word = curr.second;
            if(word == endWord) return cnt;
            for(int i = 0 ; i < word.size() ; i++){
                char og = word[i];
                for(char ch = 'a' ; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({cnt+1 , word});
                        st.erase(word);
                    }
                    word[i] = og;
                }
            }
        }
        return 0;
    }
};
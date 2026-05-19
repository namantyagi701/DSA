class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(int i = 0 ; i < wordList.size() ; i++){
            st.insert(wordList[i]);
        }
        queue<pair<string,int>>q;
        q.push({beginWord , 1});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            string word = curr.first;
            int len = curr.second;
            if(word == endWord) return len;
            st.erase(word);

            for(int i = 0 ; i < word.size() ; i++){
                string org = word;
                for(char k = 'a' ; k <= 'z' ; k++){
                    word[i] = k;
                    if(st.find(word) != st.end()){
                        q.push({word , len+1});
                    }
                }
                word = org;
            }
        }
        return 0;
    }
};
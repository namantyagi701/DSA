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
            string word = curr.first;
            int cnt = curr.second;
            q.pop();
            if(word == endWord) return cnt;
            st.erase(word);

            for(int i = 0 ; i < word.size() ; i++){
                string og = word;

                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(word == og) continue;
                    if(st.find(word) != st.end()){
                        q.push({word , cnt + 1});
                    }
                }
                word = og;
            }
        }
        return 0;
    }
};
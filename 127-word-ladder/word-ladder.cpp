class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st;
        for (int i = 0; i < wordList.size(); i++) {
            st.insert(wordList[i]);
        }
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            int cnt = ele.first;
            string word = ele.second;
            if(word == endWord) return cnt;
            st.erase(word);
            for (int i = 0; i < word.size(); i++) {
                char og = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.count(word)){
                        q.push({cnt + 1 , word});
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }
};
class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;

    string begin;
    int sz;

    void dfs(string word, vector<string>& seq) {

        if (word == begin) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mpp[word];

        for (int i = 0; i < sz; i++) {

            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {

                word[i] = ch;

                if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1) {

                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        begin = beginWord;
        sz = beginWord.size();

        for (auto it : wordList) {
            st.insert(it);
        }

        queue<string> q;
        q.push(beginWord);

        mpp[beginWord] = 0;

        st.erase(beginWord);

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int steps = mpp[word];

            if (word == endWord)
                break;

            for (int i = 0; i < sz; i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    if (st.count(word)) {

                        q.push(word);

                        st.erase(word);

                        mpp[word] = steps + 1;
                    }
                }

                word[i] = original;
            }
        }

        if (mpp.find(endWord) != mpp.end()) {

            vector<string> seq;
            seq.push_back(endWord);

            dfs(endWord, seq);
        }

        return ans;
    }
};
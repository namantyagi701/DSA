class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj[i].push_back(it);
                mpp[it].push_back(i);
            }
        }

        // outdgree

        vector<int> out(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int size = adj[i].size();
            out[i] = size;
            if (size == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for (auto it : mpp[top]) {
                out[it]--;
                if (out[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
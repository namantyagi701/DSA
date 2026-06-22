class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<int>indegree(n);
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < arr.size() ; i++){
            int u = arr[i][0];
            int v = arr[i][1];
            adj[v].push_back(u);
        }
        for(int i = 0 ; i < n ; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto it: adj[ele]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] != 0) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(V);

        for(int i = 0; i < prerequisites.size(); i++) {

            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }
        vector<int>indegree(V);
        for(int i = 0 ; i < V ; i++){
            for(auto it: adj[i]){
               indegree[it]++; 
            }
        }

        queue<int>q;
        vector<int>topo;

        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        int size = topo.size();
        if(size == V) return true;
        return false;
    }
};
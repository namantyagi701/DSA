class Solution {
public:
    bool bfs(int start , vector<vector<int>>& graph ,vector<int> &colors){
        queue<int>q;
        q.push(start);
        colors[start] = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto it: graph[curr]){
                if(colors[it] == -1){
                    colors[it] = 1 - colors[curr];
                    q.push(it);
                }
                else if(colors[it] == colors[curr]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n , -1);
        for(int i = 0 ; i < n ; i++){
            if(colors[i] == -1){
            if(!bfs(i , graph , colors)) return false;
            }
        }
        return true;
    }
};
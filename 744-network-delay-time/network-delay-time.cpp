class Solution {
public:
    int networkDelayTime(vector<vector<int>>& arr, int n, int k) {
        vector<int> time(n + 1 , 1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : arr){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v , wt});
        }
        int ans = INT_MIN;
        queue<int>q;
        q.push(k);
        time[k] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                int nodee = it.first;
                int dist = it.second;
                if(time[node] + dist < time[nodee]){
                    time[nodee] = time[node] + dist;
                    q.push(nodee);
                }
            }
        }
        for(int i = 1 ; i < time.size() ; i++){
            if(time[i] == 1e9) return -1;
            ans = max(ans , time[i]);
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};
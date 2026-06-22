class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>arr(n);
        vector<int>outorder(n,0);
        for(int i = 0 ; i < n ; i++){
            for(auto it: graph[i]){
                arr[it].push_back(i);
                outorder[i]++;
            }
        }
        queue<int>q;
        for(int i = 0 ; i < n ; i++){
            if(outorder[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int ele = q.front();
            ans.push_back(ele);
            q.pop();
            for(auto it : arr[ele]){
                outorder[it]--;
                if(outorder[it] == 0) q.push(it);
            }
        }
        if(ans.size() > 1) sort(ans.begin() ,ans.end());
        return ans;
    }
};
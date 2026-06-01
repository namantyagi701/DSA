class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n == 1) return cost[0];
        if(n == 2) return cost[0] + cost[1];
        int ans = 0;
        sort(cost.begin() , cost.end());
        int cnt = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if(cnt == 2){
               cnt = 0;
               continue;
            }
            cnt++;
            ans += cost[i];
        }
        return ans;
    }
};
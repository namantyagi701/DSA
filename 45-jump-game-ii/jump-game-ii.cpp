class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();
       if(n == 1) return 0;
       int jumps = 0;
       int end = 0;
       int farthest = 0;
       for(int i = 0 ; i < n ; i++){
          farthest = max(farthest , i + nums[i]);
          if(end == i){
             jumps++;
             end = farthest;
             if(end == n-1) return jumps;
          }
       }
       return jumps;
    }
};
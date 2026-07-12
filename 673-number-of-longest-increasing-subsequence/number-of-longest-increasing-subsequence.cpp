class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int>lis(n , 1);
        vector<int>nos(n , 1);
        int maxlis = -1;
        while(i < n){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j]){
                    if(lis[j] + 1 > lis[i]){
                        lis[i] = 1 + lis[j];
                        nos[i] = nos[j] ;
                    }
                    else if(lis[j] + 1 == lis[i]){
                        nos[i] = nos[i] + nos[j];
                    }
                }

            }
            maxlis = max(maxlis , lis[i]);
            i++;
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(lis[i] == maxlis){
                ans += nos[i];
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n );
        int pro = 1;
        int pro_zero = 1;
        bool fl = false;
        int cnt_zero = 0;
        for(int i = 0 ; i < n ; i++){
            pro *= nums[i];
            if(nums[i] == 0) cnt_zero++;
            if(nums[i] != 0){
                pro_zero *= nums[i];
                fl = true;
            }
        }
        if(!fl){
            pro_zero =  0;
        }
    
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != 0)
            temp[i] = pro / nums[i];
            
            else if(nums[i]==0){
                if(cnt_zero == 1)
                temp[i] = pro_zero;
                else{
                    temp[i] = 0;
                }
            }
        }
        return temp;
    }
};
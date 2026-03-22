class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0;
        int odd = 0;
        int even_max = INT_MAX;
        int odd_min = INT_MAX;
        for(int i = 0 ; i < nums1.size() ; i++){
            if(nums1[i] % 2 == 0){
                even_max = min(nums1[i] , even_max);
                even++;
            }
            else{
                    odd_min = min(nums1[i] , odd_min);
                odd++;
            }
        }
        if(odd == 0) return true;
        if(even == 0) return true;
        if(odd_min < even_max) return true;
        return false;
    }
};
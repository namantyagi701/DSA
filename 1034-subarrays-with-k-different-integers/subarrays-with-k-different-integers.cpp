class Solution {
public:
    int f(vector<int>& nums, int k) {
        int count = 0;
        int l = 0;
        unordered_map<int, int> mp;

        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;
            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        return f(nums, k) - f(nums, k - 1);
    }
};
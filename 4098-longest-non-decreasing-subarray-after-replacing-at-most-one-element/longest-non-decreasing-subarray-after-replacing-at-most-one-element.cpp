class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

       
        vector<int> pre(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= nums[i - 1]) {
                pre[i] = pre[i - 1] + 1;
            }
        }


        vector<int> post(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) {
                post[i] = post[i + 1] + 1;
            }
        }

        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            max_len = max(max_len, pre[i]);
        }


        int ans = (max_len < n) ? max_len + 1 : max_len;

        for (int i = 1; i < n - 1; ++i) {
            if (nums[i - 1] <= nums[i + 1]) {
                ans = max(ans, pre[i - 1] + 1 + post[i + 1]);
            }
        }

        return ans;
    }
};
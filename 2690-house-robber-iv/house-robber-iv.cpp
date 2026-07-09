class Solution {
public:
    int f(vector<int>& nums, int cap) {
        int cnt = 0;
        int last = -2;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= cap && last != i - 1) {
                cnt++;
                last = i;
            }
        }

        return cnt;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (f(nums, mid) >= k)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};
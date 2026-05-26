class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            vector<int> temp;
            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        k++;
                        l--;
                        while (k < n && nums[k] == nums[k - 1]) {
                            k++;
                        }
                        while (l >= 0 && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
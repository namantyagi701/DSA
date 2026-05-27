class Solution {
public:
    int lb(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int ub(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lb(nums, target);
        int last = ub(nums, target);
        if(first == nums.size() ||  nums[first] != target) return {-1 , -1};
        else return {first , last-1};
    }
};
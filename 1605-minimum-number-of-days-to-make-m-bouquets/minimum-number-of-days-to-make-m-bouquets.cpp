class Solution {
public:
    int calc(vector<int>& arr, int curr, int k) {
        int n = arr.size();
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= curr) {
                cnt++;
                if (cnt == k) {
                    ans++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int low = 1;
        int high = arr[0];
        for (int i = 0; i < arr.size(); i++) {
            high = max(arr[i], high);
        }
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int curr = calc(arr, mid, k);
            if (curr >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int ts = 0;
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            ts += arr[i];
        }
        int l = 0;
        int r = 0;
        int sum = 0;
        int maxSum = 0;
        while (r < n) {
            sum += arr[r];
            if ((r - l + 1) > (n - k)) {
                sum -= arr[l];
                l++;
            }
            if ((r - l + 1) == (n - k)) {
                maxSum = max(maxSum, (ts - sum));
            }
            r++;
        }
        return maxSum;
    }
};
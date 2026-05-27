class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int ans = x;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long curr = 1LL * mid * mid;
            if (curr == x)
                return mid;
            else if (curr < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
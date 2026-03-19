class Solution {
public:
    int dp[1001][1001][2][2];;

    int f(int i, int prev, int phase, int flag, vector<int>& arr) {
        if(i == arr.size()) {
            if(phase == 1 && flag) return 0;
            return -1e9;
        }

        if(dp[i][prev+1][phase][flag] != -1)
            return dp[i][prev+1][phase][flag];

        int notTake = f(i + 1, prev, phase, flag , arr);
        int take = -1e9;

        if(prev == -1) {
            take = 1 + f(i + 1, i, 0, 0 , arr);
        }
        else {
            if(phase == 0) {
                if(arr[i] > arr[prev]) {
                    take = max(take, 1 + f(i + 1, i, 0, 1 , arr));
                }
                if(arr[i] < arr[prev] && flag) {
                    take = max(take, 1 + f(i + 1, i, 1, flag , arr));
                }
            }
            else {
                if(arr[i] < arr[prev]) {
                    take = max(take, 1 + f(i + 1, i, 1, flag , arr));
                }
            }
        }

        return dp[i][prev+1][phase][flag] = max(take, notTake);
    }

    int minimumMountainRemovals(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int res = f(0, -1, 0, 0 , nums);
        if(res < 3) return nums.size();
        return nums.size() - res;
    }
};
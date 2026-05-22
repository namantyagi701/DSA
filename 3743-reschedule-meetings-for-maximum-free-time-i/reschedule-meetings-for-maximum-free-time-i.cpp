class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {

        int n = startTime.size();
        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for(int i = 1; i < n; i++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime[n - 1]);
        int window = k + 1;
        int sum = 0;
        for(int i = 0; i < window; i++) {
            sum += gaps[i];
        }
        int maxSum = sum;
        for(int r = window; r < gaps.size(); r++) {

            sum += gaps[r];
            sum -= gaps[r - window];

            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
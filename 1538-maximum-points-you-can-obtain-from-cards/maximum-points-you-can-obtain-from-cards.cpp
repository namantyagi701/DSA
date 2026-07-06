class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(n < k) return 0;
        int ts = 0;
        for(int i = 0 ; i < n ; i++){
            ts += cardPoints[i];
        }
        int i = 0;
        int j = 0;
        long long sum = 0;
        long long mini = 1e9;
        while(i < n && j < n){
            // int len = (j - i + 1);
            if((j-i+1) > (n - k)){
                sum -= cardPoints[i];
                i++;
            }
            sum += cardPoints[j];
            if(j - i + 1 == n - k)
            mini = min(mini , sum);
            j++;
        }
        return ts - mini;
    }
};
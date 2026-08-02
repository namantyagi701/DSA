class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int sum = 0;
        int n = piles.size();
        if(n == 2) return true;
        for(int i = 0 ; i < n ; i++){
            sum += piles[i];
        }
        sum = sum/2;
        int i = 0;
        int j = n-1;
        int alice_sum = 0;
        while(i < j){
           alice_sum += max(piles[i] , piles[j]);
           i++;
           j--;
        }
        if(alice_sum > sum) return true;
        return false;
    }
};
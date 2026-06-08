class Solution {
public:
    bool f(vector<int>& hand , int gs , int i , int n){
        int next = hand[i] + 1;
        hand[i] = -1;
        int cnt = 1;
        i += 1;
        while(i < n && cnt < gs){
            if(hand[i] == next){
            next = hand[i] + 1;
            hand[i] = -1;
            cnt++;
            }
            i++;
        }
        return cnt == gs;
    }
    bool isNStraightHand(vector<int>& hand, int gs) {
        sort(hand.begin() , hand.end());
        int n = hand.size();
        if((n %  gs) != 0) return false;
        for(int i = 0 ; i < n ; i++){
            if(hand[i] >= 0){
                if(!f(hand , gs , i , n)) return false;
            }
        }
        return true;
    }
};
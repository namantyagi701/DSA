class Solution {
public:
    bool hasAlternatingBits(int n) {
      int prev = -1;
      while(n > 0){
        int curr = (n%2);
        if(curr == prev){
            return false;
        }
       prev = curr;
       n = n/2;
      }
      return true;
    }
};
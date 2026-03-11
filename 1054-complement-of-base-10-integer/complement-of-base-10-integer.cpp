class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int temp = n;
        vector<int>ans;
        while(temp){
          int k = temp % 2;
          ans.push_back(k);
          temp = temp/2;
        }
        reverse(ans.begin() , ans.end());
        for(int i = 0 ; i < ans.size() ; i++){
            ans[i] = ans[i]^1;
        }
        int p = 0;
        int res = 0;
        for(int i = ans.size()-1 ; i >=0 ; i--){
          int t = ans[i] * pow(2 , p);
          res +=t;
          p++;
        }
        return res;
    }
};
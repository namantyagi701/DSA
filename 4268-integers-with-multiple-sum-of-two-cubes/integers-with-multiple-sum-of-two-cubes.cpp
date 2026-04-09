class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int>res;
        unordered_map<int , int> freq;
        int k = cbrt(n);
        for(int i = 0 ; i <= k ; i++){
            for(int j = i + 1 ; j <= k ; j++){
                long long ans = (1LL * i * i * i) + (j * j * j);
                if(ans > n) break;
                freq[ans]++;
            }
        }
        for(auto it: freq){
            if(it.second >= 2){
                res.push_back(it.first);
            }
        }
        sort(res.begin() , res.end());
        return res;
    }
};
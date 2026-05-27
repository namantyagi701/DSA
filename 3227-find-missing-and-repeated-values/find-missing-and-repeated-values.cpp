class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        vector<int>temp;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                temp.push_back(arr[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        int m = -1;
        int tw = -1;
        int sum = temp[0];
        for(int i = 1 ; i < temp.size() ; i++){
            sum += temp[i];

            if(temp[i] == temp[i-1]){
                tw = temp[i];
            }
        }
        int x = temp.size();
        int org = (x*(x+1))/2;
        int diff = org - sum;
        m = tw + diff;
        return {tw , m};
    }
};
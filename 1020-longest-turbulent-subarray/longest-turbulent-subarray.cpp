class Solution {
public:
    int f(int i , bool flag , vector<int> &arr){
        if(i >= arr.size()) return 0;
        int take = 0;
        int maxi = 0;
        if(flag){
            if(arr[i-1] < arr[i]) take = 1 + f(i + 1 , !flag , arr);
            else return 0;
        }
        else{
            if(arr[i-1] > arr[i]) take = 1 + f(i + 1, !flag , arr);
            else return 0;
        }
        return take;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        int ans = 0;
        for(int i = 1 ; i < n ; i++){
            int ans1 = f(i , true , arr);
            maxi = max(maxi , f(i , false ,arr));
            maxi=max(maxi,ans1);
        }
        return 1+maxi;       
    }
};
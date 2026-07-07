class Solution {
public:
    static bool comp(vector<int> &a , vector<int>& b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        sort(points.begin() , points.end() , comp);
        int cnt = 0;
        long long free = -1e9;
        bool used = false;
        for(int i = 0 ; i < n ; i++){
            if(!used){
                cnt++;
                free = points[i][1];
                used = true;
                continue;
            }
            if(free < points[i][0]){
                cnt++;
                free = points[i][1];
            }
        }
        return cnt;
    }
};
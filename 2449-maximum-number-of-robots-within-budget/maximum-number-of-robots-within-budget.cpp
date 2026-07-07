class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long budget) {
        int i = 0;
        int j = 0;
        int n = ct.size();
        long long sum = 0;
        int ans = 0;
        deque<int>dq;
        while(i < n && j < n){
            sum += rc[j];
            while(!dq.empty() && dq.back() < ct[j]){
                dq.pop_back();
            }
            dq.push_back(ct[j]);
            
            long long cost = dq.front() + 1LL * (j - i + 1) * sum;
            while(i < n && cost > budget){
               sum -= rc[i];
               if(dq.front() == ct[i]){
                 dq.pop_front();
               }
               i++;
               cost = dq.front() + 1LL * (j - i + 1) * sum;
            }
            ans = max(ans , (j - i +1));
            j++;
        }
        return  ans;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        list<int> st;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0)
                st.push_back(arr[i]);
            else {
                while(!st.empty() && st.back() > 0 && abs(st.back()) < abs(arr[i])) st.pop_back();
                if(!st.empty() && st.back() > 0 && abs(arr[i]) == abs(st.back())) st.pop_back();
                else if(st.empty() || st.back() < 0) st.push_back(arr[i]); 
            }
        }
        return vector<int>(st.begin(), st.end());
    }
};
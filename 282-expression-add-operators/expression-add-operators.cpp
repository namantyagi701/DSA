class Solution {
public:
    void solve(int index, string path, long long value, long long prev,
               string& num, int target, vector<string>& ans) {

        // reached end
        if (index == num.size()) {
            if (value == target) {
                ans.push_back(path);
            }
            return;
        }

        string currStr = "";
        long long currNum = 0;

        for (int i = index; i < num.size(); i++) {

            if (i > index && num[index] == '0')
                break;

            currStr += num[i];
            currNum = currNum * 10 + (num[i] - '0');

            if (index == 0) {

                solve(i + 1, currStr, currNum, currNum, num, target, ans);
            } else {

  
                solve(i + 1, path + "+" + currStr, value + currNum, currNum,
                      num, target, ans);

         
                solve(i + 1, path + "-" + currStr, value - currNum, -currNum,
                      num, target, ans);

     
                solve(i + 1, path + "*" + currStr,
                      value - prev + (prev * currNum), prev * currNum, num,
                      target, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        solve(0, "", 0, 0, num, target, ans);

        return ans;
    }
};
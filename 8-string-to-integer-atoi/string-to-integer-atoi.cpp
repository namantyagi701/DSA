class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        while(i < n && s[i] == ' '){
            i++;
        }
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-')
            sign = -1;
            i++;
        }
        int no = 0;
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            if(no >  (INT_MAX - digit)/10){
                return (sign == -1) ? INT_MIN : INT_MAX;
            }
            no = no * 10 + digit;
            i++;
        }
        return sign * no;
    }
};
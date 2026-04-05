class Solution {
public:
    bool judgeCircle(string moves) {
        int k = 0;
        int j = 0;
        for(int i = 0 ; i < moves.size() ; i++){
            if(moves[i] == 'R'){
                j++;
            }
            else if(moves[i] == 'L'){
                j--;
            }
            else if(moves[i] == 'U'){
                k--;
            }
            else{
                k++;
            }
        }
        return (k == 0 && j == 0);
    }
};
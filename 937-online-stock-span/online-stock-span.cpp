class StockSpanner {
public:
    vector<int>vect;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int n = vect.size();
        if(n == 0){
             vect.push_back(price);
             return 1;
             }
        int cnt = 1;
        int i = n-1;
        while( i >= 0 && price >= vect[i]){
            cnt++;
            i--;
        }
        vect.push_back(price);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
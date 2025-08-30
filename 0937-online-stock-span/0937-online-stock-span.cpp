class StockSpanner {
    stack<pair<int,int>> s;
    int index=-1;
public:
    StockSpanner() {
        s.push({1e8,-1});
    }
    
    int next(int price) {
        index++;
        if(price<s.top().first){
            s.push({price,index});
            return 1;
        }
        else{
            while(!s.empty() && s.top().first<=price){
                s.pop();
            }
            int temp=index-s.top().second;
            s.push({price,index});
            return temp;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
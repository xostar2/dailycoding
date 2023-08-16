class StockSpanner {
public:
    vector<int>v;
    stack<int>s;
    StockSpanner() {
        s.push(0);
        v.push_back(1e6);
    }
    
    int next(int price) {
        while(price>=v[s.top()]){
            s.pop();
        }
        int ans=v.size()-s.top();
        s.push(v.size());
        v.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
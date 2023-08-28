class MyStack {
public:
    MyStack() {
        
    }
    queue<int>q1;
    
    void push(int x) {
        q1.push(x);
        int n=q1.size();
        for(int i=0;i<n-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
         
        
    }
    
    int pop() {
       
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {  
        int x=q1.front();
        return x;
    }
    
    bool empty() {
        if(q1.size()==0 )return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
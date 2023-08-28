class MyStack {
public:
    MyStack() {
        
    }
    queue<int>q1;
    queue<int>q2;
    void push(int x) {
        q2.push(x);
        
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
        
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
        if(q1.size()==0 and q2.size()==0)return true;
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
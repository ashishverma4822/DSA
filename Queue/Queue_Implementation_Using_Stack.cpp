class MyQueue {
public:
    stack<int>a,b;
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        int val=peek();
        b.pop();
        return val;
    }
    
    int peek() {
        if(b.empty()){
            while(a.empty()!=true){
                b.push(a.top());
                a.pop();
            }
        }
        return b.top();
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
};

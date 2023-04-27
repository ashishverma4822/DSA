class MyQueue {
public:
    int v[200];
    int f=0,r=0;
    MyQueue() {
        
    }
    void push(int x) {
        if(r!=200){
            v[r]=x;
            r++;
        }
    }
    int pop() {
        if(!empty()){
            f++;
            return v[f-1];
        }
        return false;
    }
    int peek() {
        return v[f];   
    }
    
    bool empty() {
        if(f==r){
            f=0;
            r=0;
            return true;
        }
        return false;
    }
};

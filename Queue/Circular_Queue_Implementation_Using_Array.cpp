class MyCircularQueue {
public:
    int r;
    int f;
    int s;
    int *arr;
    MyCircularQueue(int k) {
        arr = new int[k];
        r=-1; f=-1;
        s=k;
    }
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        r=(r+1)%s;
        arr[r]=value;
        if(f==-1) f=0;
        return true;
    }
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        if(f==r){
            f=-1;
            r=-1;
        }
        else{
            f=(f+1)%s;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[f];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[r];
    }
    
    bool isEmpty() {
        if(f==-1) return true;
        else return false;
    }
    
    bool isFull() {
        if((r+1)%s==f) return true;
        else return false;
    }
};

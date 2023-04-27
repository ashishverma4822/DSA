#include <bits/stdc++.h> 
class Deque
{
public:
    // Initialize your data structure.
    int front,rear,size,*arr;
    Deque(int n)
    {
        arr = new int[n];
        front=-1;
        rear=-1;
        size=n;
        // Write your code here.

    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {

        // Write your code here.
        if(isFull()) return false;
        else{
            if(front==-1){
                front=rear=0;
            } 
            else{
                if(front==0) front=size-1;
                else front--;
            }
            arr[front]=x;
            return true;
        }

    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull()) return false;
        else{
            if(front == -1) front=rear=0;
            else rear=(rear+1)%size;
            arr[rear]=x;
            return true;
        }
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        int val=getFront();
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else front=(front+1)%size;
        return val;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        int val = getRear();
        if(front==rear){
            front=rear=-1;
        }
        else{
            if(rear==0) rear=size-1;
            else rear--;
        }
        return val;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        else return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        else return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front==-1) return true;
        else return false;

    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((rear+1)%size==front) return true;
        else return false;

    }
};

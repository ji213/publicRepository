#include "queue.h"
#include <iostream>

Queue::Queue(){
    front = -1;
    rear = -1;
    for(int i=0; i<5; i++){
        arr[i] = 0;
    }
}

bool Queue::isEmpty(){
    if(front==-1 && rear == -1){
        return true;
    }
    else {
        return false;
    }
}

bool Queue::isFull(){
    if(rear==4){
        return true;
    }
    else{
        return false;
    }

}

void Queue::enqueue(int val){
    if(isFull()){
        std::cout << "Queue is full\n";
        return;
    }
    else if(isEmpty()){
        rear=0;
        front=0;
        arr[rear] = val;
    }
    else{
        rear++;
        arr[rear] = val;
    }
}

int Queue::dequeue(){
    int x;
    if(isEmpty()){
        std::cout << "Queue is empty\n";
        return 0;
    }
    else(front == rear){
        x = arr[front];
        arr[front] = 0;
        rear = -1;
        front = -1;
        return x;
    }
    else{
        x = arr[front];
        arr[front] = 0;
        front++;
        return x
    }
}

int Queue::count(){
    return (rear - front + 1);
}
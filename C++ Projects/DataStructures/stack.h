#pragma once


class Stack {
    private:
        int top;
        int arr[5];
    public:
        Stack();
        bool isEmpty();
        bool isFull();
        void push(int val);
        int pop();
        int count();
        int peek(int pos);
        void change(int pos, int val);
        void display();
};
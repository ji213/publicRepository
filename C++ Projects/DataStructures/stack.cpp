#include "stack.h"
#include <iostream>

Stack::Stack(){
        top = -1;
        for (int i = 0; i < 5; i++){
                arr[i] = 0;
            }
}

bool Stack::isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }

bool Stack::isFull(){
            if(top==4){
                return true;
            }
            else{
                return false;
            }
        }

void Stack::push(int val){
            if(isFull()){
                std::cout << "Stack overflow \n\n";
            }
            else{
                top++;
                arr[top] = val;
            }
        }

int Stack::pop(){
            if(isEmpty()){
                std::cout << "stack underflow \n\n";
                return 0;
            }
            else{
                //Set value to top of stack
                int popValue = arr[top];
                //Set top of stack to 0, hence pop
                arr[top] = 0;

                //decrement the 'top' index
                top--;

                return popValue;

            }
        }

int Stack::count(){
            return (top + 1);
        }

int Stack::peek(int pos){
            if(isEmpty()){
                std::cout << "Stack underflow \n\n";
            }
            else{
                return arr[pos];
            }
        }

void Stack::change(int pos, int val){
            arr[pos] = val;
            std::cout << "Value changed at location " << pos << "\n\n";
        }

void Stack::display(){
            std::cout << "All values in the Stack are \n\n";
            for(int i = 4; i >= 0; i++){
                std::cout << arr[i] << "\n";
            }
        }
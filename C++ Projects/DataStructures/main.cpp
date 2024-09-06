//  Data Structures v0.1
// In order to compile, need to call the class cpp files while compiling
// ex command: g++ main.cpp stack.cpp -o main



#include <iostream>
#include <string>
#include "stack.h"



int main(){

    //Stack 
    Stack s1;
    int option, position, value;
    bool result;

    do{
        std::cout << "What operation do you want to perform? Select option number. Enter 0 to exit \n";
        std::cout << "1. Push() \n2. Pop() \n3. isEmpty() \n4. isFull() \n5. peek() \n6. count() \n7. change() \n8. display() \n9. Clear screen \n\n";
    
        std::cin >> option;
        switch(option){
            case 1:
                //push
                std::cout << "Enter an item to push in the stack \n";
                std::cin >> value;
                s1.push(value);
                break;
            case 2:
                //pop
                std::cout << "Pop Function called... poped value: " << s1.pop() << "\n";
                break;
            case 3:
                //isEmpty
                result = s1.isEmpty();
                switch(result){
                    case true:
                        std::cout << "Stack is empty \n\n";
                        break;
                    case false:
                        std::cout << "Stack is not empty \n\n";
                        break;
                    default:
                        std::cout << "Unexpected outcome \n\n";

                }
                break;
            case 4:
                //isFull
                break;
            case 5:
                //peek
                break;
            case 6:
                //count
                break;
            case 7:
                //change
                break;
            case 8:
                //display
                break;
            case 9:
                //clear screen
                break;


        }

    }while(option != 0);


    return 0;
}

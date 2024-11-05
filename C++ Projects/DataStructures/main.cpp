//  Data Structures v0.3
// In order to compile, need to call the class cpp files while compiling
// ex command: g++ main.cpp stack.cpp -o main


//ERROR LOG:
//  Issue with display(), returning abnormal amount of data





#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"



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
                if(s1.isEmpty()){
                    std::cout << "Stack is Empty\n\n";
                }
                else{
                    std::cout << "Stack is not empty\n\n";
                }
                break;
            case 4:
                //isFull
                if(s1.isFull()){
                    std::cout << "Stack is full\n";
                }
                else{
                    std::cout << "Stack is not full\n";
                }
                break;
            case 5:
                //peek
                std::cout << "Enter the position of item you want to peek\n";
                std::cin >> position;

                std::cout << "Peek function called...\n Value at position " << position << " : " << s1.peek(position) << "\n\n";
                break;
            case 6:
                //count
                std::cout << "Count function called ...\n Number of items in the Stack are: " << s1.count() << "\n\n";
                break;
            case 7:
                //change
                std::cout << "Change function called...\n Enter the position of the item you want to change: ";
                std::cin >> position;

                std::cout << "\n";
                std::cout << "Enter the value of item you want to change: ";
                std::cin >> value;

                s1.change(position, value);
                break;
            case 8:
                //display
                std::cout << "Display function called - \n";
                s1.display();
                break;
            case 9:
                //clear screen
                system("cls");
                break;
            default:
                std::cout << "Please enter correct option number\n\n";


        }

    }while(option != 0);

    //Queue Logic


    return 0;
}

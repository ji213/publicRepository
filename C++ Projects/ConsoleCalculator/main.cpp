#include <iostream>
#include <stdexcept>

// Console Calculator Application
// Version 1.0



// Things to look into:
// Program crashes if number entered is abnormal ... ex: num1 = 1.000,5003

char validateLoopCharacter(char x) {
    char result = tolower(x);

    if (result == 'y' || result == 'n'){
        std::cout << "Successful input\n";
    }
    else {
        std::cout << "Test run... result = " << result << "\n";
        throw std::runtime_error("ERROR !@#$ Invalid character! Please only enter y or n");
    }

    return result;
}

int main(){
    // Declare variables
    char op;
    double num1;
    double num2;
    double result;
    char loop;

    //Take user input for variable values
    std::cout << "Console Calculator \n";

    std::cout << "Would you like to begin? (y/n) ";
    std::cin >> loop;

    loop = validateLoopCharacter(loop);

    while(loop == 'y'){

        std::cout << "Enter either (+ - * /): ";
        std::cin >> op;

        std::cout << "Enter number 1: ";
        std::cin >> num1;

        std::cout << "Enter number 2: ";
        std::cin >> num2;

        //use switch function to write out 
        //which function to perform based on the user input operator
        switch(op){
            case '+':
                result = num1 + num2;
                std::cout << "result: " << result << "\n";
                break;
            case '-':
                result = num1 - num2;
                std::cout << "result: " << result << "\n";
                break;
            case '*':
                result = num1 * num2;
                std::cout << "result: " << result << "\n";
                break;
            case '/':
                if(num2 == 0){
                    throw std::runtime_error("ERROR !@#$ You attempted to divide by zero... This isn't allowed\n");
                }
                result = num1/num2;
                std::cout << "result: " << result << "\n";
                break;
            default:
                std::cout << "Invalid operator was supplied. Please try again";
                break;


        }

        std::cout << "Would you like to try again? (y/n) ";
        std::cin >> loop;
        loop = validateLoopCharacter(loop);

    }
    std::cout << "******************* \n";
   
}
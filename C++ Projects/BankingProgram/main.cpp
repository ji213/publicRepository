// Banking Program v1.1

// Create banking program that allows user to perform the following:
// 1. deposit money
// 2. withdraw money
// 3. check balance
// 4. Brainstorm further functions later, such as check deposit, user accounts, etc.

// TODO: Add logging and validation in various spots
// Input validation for various variables
// Try to replace runtime errors with second attempts rather then exiting
// Add as much logic to functions as possible to simply main loop


#include <iostream>
#include <stdexcept>
#include <string>
#include <ctime>

// Global Variables
double maxDepositAmount = 100000;

//initialize functions

void randomizeInitialBalance(double& balance);

void checkBalance(double balance);

void depositToAccount(double& balance);

void withdrawFromAccount(double& balance);

int main (){

    //Declare local variables
    double accountBalance = 0;
    double amount;
    char loop;
    int userSelection;
    std::string acceptedLoopInput = "yYnN";
    int validInput[3] = {1, 2, 3};
    bool isValid;
    
    

    // Welcome message
    std::cout << "***** Welcome to the Bank (v1.0) *****\n";

    // Call randomize function to initialize balance
    randomizeInitialBalance(accountBalance);

    std::cout << "Done! Your starting balance is ... $" << accountBalance << "\n";


    //loop through all actions
    do{
        // ask user which action they would like to execute
        while (true){
            std::cout << "What action would you like to take? \n1. Check Balance \n2. Withdraw $ \n3. Deposit $ \n";

            // TODO: Add validation on input
            // eventually add comparison to array validInput
            std::cin >> userSelection;
            isValid = std::find(std::begin(validInput), std::end(validInput), userSelection) != std::end(validInput);
            if(std::cin.fail() || !isValid){
                std::cout << "Invalid input supplied... Please try again";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


            }
            else{
                std::cout << "Successful input \n\n\n";
                break;
            }

        }

        // call functions for option selected
        switch(userSelection){
            case 1:
                //Check Balance
                checkBalance(accountBalance);
                break;
            case 2:
                // Withdraw $
                withdrawFromAccount(accountBalance);
                break;
            case 3:
                //Deposit $
                depositToAccount(accountBalance);
                break;
            default:
                throw std::runtime_error("ERROR !@#$ you did not select a valid action.... please try again next time :/");
        }


        // ask user if they would like to complete another function or exit loop
        std::cout << "Would you like to execute another action?(y/n) ";
        std::cin >> loop;
        loop = tolower(loop);

        // validate input
        if(acceptedLoopInput.find(loop) != std::string::npos){
            std::cout << "..... \n";
        }
        else {
            throw std::runtime_error("ERROR !@#$ Invalid input received... try again next time \n");
        }



    }while(loop == 'y');
    



    return 0;
}

void randomizeInitialBalance(double& balance){

    //randomizer
    srand(time(NULL));

    // Start users off with random amount in account
    std::cout << "For now, we will put a random amount in your account to test basic functionality... \n";

    std::cout << "Randomizing amount... \n";

    //randomize account balance up to $1m
    balance = rand() % 1000000;

}

void checkBalance(double balance){

    //Return balance to the user

    std::cout << "Account Balance: $" << balance << "\n";

}

void depositToAccount(double& balance){
    //Ask user how much they would like to deposit
    int userInput;

    std::cout << "You selected Deposit...\nHow much would you like to deposit";
    //TODO: add input validation here
    std::cin >> userInput;

    // Make sure deposit amount doesn't exceed maximum amount policy
    if (userInput >= maxDepositAmount){
        throw std::runtime_error("ERROR !@#$ Maximum Deposit Amount exceeded... please try again. The threshold is: " + std::to_string(maxDepositAmount) + "\n\n");
    }
    else {
        balance = balance + userInput;
        std::cout << "Deposit Successful \n";
    }


}

void withdrawFromAccount(double& balance){
    //Ask user how much they would like to withdraw
    int userInput;

    std::cout << "You selected Withdraw...\nHow much would you like to withdraw? ";
    //TODO: add input validation here
    std::cin >> userInput;

    if(balance >= userInput){
        balance = balance - userInput;
        std::cout << "Withdrawal successful \n";
    }
    else {
        throw std::runtime_error("ERROR !@#$ Withdrawal amount is larger than current balance \n\n");
    }
    


}
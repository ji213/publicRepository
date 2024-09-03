// Temperature conversion program
// 
// Take user input in either F or C and convert it to the other unit of measurement


//****ERROR LOG********
// Add error handling for all errors listed



#include <iostream>
#include <stdexcept>
#include <string>

double FarenheitToCelcius (double input ){
    // Function returns calculation from F -> C
    // C = (F - 32)(5/9)

    double result;


    //std::cout << "\nInput value (F to C): " << input;
    result = input - 32;
    //std::cout << "result after step 1: " << result;
    result = result * 5 / 9;

    //can add console output here to log when function is called

    //std::cout << "\nResult: " << result;

    return result;

}

double CelciusToFarenheit (double input){
    //Function returns calculation from C -> F
    // F = (9/5)(C) + 32

    double result;

    //std::cout << "\nInput Value (C to F): " << input;
    result = input * 9 / 5;
    result = result + 32;


    //can add console output here to log when function is called
    //std::cout << "\nResult: " << result;
    return result;

}

int main(){

    // Declare variable
    char unitOfMeasurement;
    char loop;
    double userInput;
    double calculationOutput;

    std::string validUnitofMeasurement = "fFcC";
    std::string validuserInput = "yYnN";

    //Welcome statement
    std::cout << "Welcome to the Console Temperature Conversion Program\n";
    std::cout << "You can enter a temperature in farenheit or celcius, and we will convert it for you \n";

    // are you ready to begin?
    // add validation here to prevent errors
    std::cout << "Ready to start? (y/n) ";
    std::cin >> loop;

    loop = tolower(loop);
    //
    if(loop == 'y' || loop == 'n'){
        std::cout << "Success!\n";
    }
    else{
        throw std::runtime_error("ERROR !@#$ Invalid input! Please only enter y or n");
    } 

    
    //while loop to allow multiple attempts

    while(loop != 'n'){

    
        //Take user input for the unit of measurement (F or C)
        while(true){

            std::cout << "What unit of measurement would you like to start with (F or C)?  ";
            std::cin >> unitOfMeasurement;

            if(std::cin.fail() || !validUnitofMeasurement.find(unitOfMeasurement)){
                std::cout << "Invalid input... please try agian";
            }
            else{
                break;
            }
        }

        unitOfMeasurement = toupper(unitOfMeasurement);

        if(unitOfMeasurement == 'F' || unitOfMeasurement == 'C'){
            //Log to console what unit they chose
            std::cout << "Unit of Measurement: " << unitOfMeasurement;
        }
        else {
            //Throw runtime_error... UI should return here or restart console
            throw std::runtime_error("ERROR !@#$ Invalid unit of measurement supplied. Try again next time");
        }

        //Take user input for value to convert
        // Add validation here to prevent endless loop on incorrect data supplied

        std::cout << "\nEnter value to convert in " << unitOfMeasurement << " :";
        std::cin >> userInput;

        std::cout << "Converting values ....\n";
        //std::cout << "Unit of Measurement: " << unitOfMeasurement;
        //std::cout << "\nUser Input Value: " << userInput;

        //perform conversion using functions above
        switch(unitOfMeasurement){
            case 'F':
                calculationOutput = FarenheitToCelcius(userInput);
                break;
            case 'C':
                calculationOutput = CelciusToFarenheit(userInput);
                break;
            default:
                std::cout << "Something went wrong... we'll let you try again";
                break;
        }

        //return result back to the console

        std::cout << "\nResult : " << calculationOutput << (unitOfMeasurement == 'C' ? " Farenheit" : " Celcius");

        //ask if they would like to continue
        std::cout << "Would you like to try again? (y/n) ";
        std::cin >> loop;

        loop = tolower(loop);
    
    }


    std::cout << "********** End of Program **********\n";

 

}
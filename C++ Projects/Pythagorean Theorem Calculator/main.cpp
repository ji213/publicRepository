#include <iostream>
#include <cmath>
#include <cctype>

//typedef std::vector<std::pair<std::string, int>> pairlist_t;
//typedef std::string text_t;
//typedef int number_t;


int main(){

    double a;
    double b;
    double c;
    char cont = 'n';

    while(cont != 'y'){
        std::cout << "This is a Pythagorean Theorem Calculator \n";
        std::cout << "Enter side A: ";
        std::cin >> a;

        std::cout << "Enter side B: ";
        std::cin >> b;

        c = sqrt(pow(a,2) + pow(b, 2));

        std::cout << "Side C: " << c << '\n';

        std::cout << "Do you want to go again? ";
        std::cin >> cont;

        //change to lower case to prevent inconsistencies
        tolower(cont);

        if((cont != 'y') || (cont != 'n')){
            std::cout << "Error!@#$ Invalid character! Returning Loop \n";

            return 1;
        }


    }

    return 0;

}
//Number Guessing Game v1.0

//ERROR LOG/ THINGS TO ADD
// Time logging


#include <iostream>
#include <ctime>
#include <stdexcept>

int main() {

    //Declare variables
    int num;
    int guess;
    int tries = 0;
    int highScore = 0;
    char loop = 'y';

    srand(time(NULL));

    std::cout << "***** NUMBER GUESSING GAME *****\n";

    do{
        std::cout << "Are you ready to begin?(y/n) ";
        std::cin >> loop;

        loop = tolower(loop);

        if(loop == 'y' | loop == 'n'){
            if(loop == 'y'){
                std::cout << "Starting game now... \n";
            }
            else {
                std::cout << "Ending game... \n";
                break;
            }

        }
        else {
            //throw runtime error
            throw std::runtime_error("ERROR !@#$ Invalid character supplied... try again next time \n");

        }

        //Init random number
        num = (rand() % 100) + 1;


        do{
            std::cout << "Enter a guess between (1-100): ";
            std::cin >> guess;
            tries++;

            if(guess > num){
                std::cout << "Incorrect! Your guess was too high.\n";
            }
            else if(guess < num){
                std::cout << "Incorrect! Your guess was too low. \n";
            }
            else{
                std::cout<< "Lucky guess... that is correct!\n";
                break;
            }

        }while(guess != num);

        std::cout << "Well done! That took you " << tries << " tries!\n";

        //Compare to high score

        if(highScore == 0){
            // If highScore == 0, take value from tries
            highScore = tries;

        }
        else if(highScore >= tries > 0){
            highScore = tries;

        }
        else{
            throw std::runtime_error("ERROR Occured during high score calculation...\n high score: " + std::to_string(highScore) + "\n tries this round: " + std::to_string(tries) + "\n");
        }

        std::cout << "Your current high score is " << highScore << "\n";

        //Ask if you would like to try again
        std::cout << "Would you like to go again?(y/n) ";
        std::cin >> loop;

        loop = tolower(loop);

        if(loop == 'y' | loop == 'n'){
            std::cout << "...... \n";

        }
        else {
            //throw runtime error
            throw std::runtime_error("ERROR !@#$ Invalid character supplied... try again next time \n");

        }


    }while(loop == 'y');

    // Log results to user console
    std::cout << "Thank you for participating... \n";
    if(highScore > 0){
        std::cout << "Your high score was: " << highScore << "\n";
    }
    else{
        std::cout << "You didn't attempt the game, so you don't have a high score to display \n";
    }

    std::cout << "Come again soon! \n\n\n";
    

    return 0;


}
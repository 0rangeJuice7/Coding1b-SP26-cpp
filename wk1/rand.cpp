// Roman Henson Coding 1 Spring 2026
// Random Numbers, Switch Statements, & While Loops22

// to compile, open Terminal
// navigate to this folder with 'cd' for 'change directory'
// use the command 'clang++ -o rand rand.cpp' to compile
// and then type './rand' to run the program

// Fill out the rest of the code so that it displays the words "Random Numbers" to the console then run it

#include <iostream>
#include <cstdlib>          // for srand and rand
#include <ctime>             // for time

using namespace std;

int main () {
    // only once, at the beginning of the program
    // seed the random number generator
    srand(time(0));

    cout << "Random Numbers" << endl;

    cout << "Here is our first random number: " << rand() << ".\n";

    int counter = 0;
    while(counter++ < 10) {
        int number = rand();
        int min = 50;
        int max = 100;
        int range = max - min;          // 50
        int clampedNumber = (number % range) + min;

        cout << clampedNumber << endl;
    }
    
    // set variables
        // the random number
        int randomRange = (rand() % 11) + 10;           //this gives us a number between 10 and 20 (inclusive)
        int number = (rand() % randomRange) + 1;

        // the guess/input
        int guess = -1;

        int totalGuesses = 0;
    // start loop
    while(true) {
        // ask for the player's guess between 1-10 (inclusive)
        cout << "I'm thinking of a number between 1 and " << randomRange << ", can you guess it?\n>>";
        // get the player's guess/input
        cin >> guess;
        totalGuesses++;
        // evaluate player's guess for
            // too high
            if(guess > number) {
                cout << "Too high!\n";
            }
            // too low
            else if(guess < number) {
                cout << "Too low\n";
            }
            // correct!
            else {
                cout << "That's right! You guessed correctly!\n";
                // break out of loop
                break;
            }
    } // if Incorrect guess, keep looping


    return 0;
}
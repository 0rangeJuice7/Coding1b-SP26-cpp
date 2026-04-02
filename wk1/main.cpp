//Roman Henson Coding 1 Spring 2026
// Variables and Logic

// to compile, open Terminal
// navigate to this folder with 'cd' for 'change directory'
// use the command 'clang++ -o main main.cpp' to compile
// and then type './main' to run the program

#include <iostream>
using namespace std;

int main() { 
    cout << "Let's learn about variables and logic!\n";


    // declaring and defining variables.
    int playerAge = -1;
    string playerName = "Orange Julius";
    float happinessPercent = 0.61f;
    bool keepPlaying = true;

    // just like a branch in unreal engine
    // if (the test is true) run this code. 
    if(playerAge == -1) {
        cout << "How old are you?\n";
        cin >> playerAge;

        if(playerAge <= 12) {
            cout << "I'm sorry, this game is for grown ups!\n";
            return 0;       // quit the game early
        }
        else {
            cout << "Wow, " << playerAge << " years, that is a long time!\n";
        }

    } // end of if(playerAge)

    if(playerName == "Orange Julius") {
        cout << "is your name " << playerName << "?\n";
        string input;       // create a new string variable to keep track of user input
        cin >> input;       // get the user input

        // the OR operator '||' means that if any test evaluates to true, the if statement is true
        if(input == "yes" || input == "Yes" || input == "YES") {
            cout << "Well, that's convenient!\n";
        }
        else {
            cout << "What is your name?\n";
            cin >> playerName;
        }

        cout << "Hello " << playerName << ".\n";
        
    } // end of if(playerName)

    bool debug = false;     // turn this on to debug the program

    // the AND operator '&&' requires that all tests are true.
    if(playerAge == 37 && playerName == "Brian") {
        debug = true;
        cout << "Hello Creator. Debug mode is ON.\n";

    } // end of if(age && name)

    if(debug) {
        cout << "\n\tDEBUG MODE\n\n";
        cout << "playerAge = " << playerAge << ".\n";
        cout << "playerName = " << playerName << ".\n";
        cout << "happinessPercent = " << happinessPercent << ".\n";
        cout << "keepPlaying = " << keepPlaying << ".\n";
    }

    



    return 0;

} // end of main()
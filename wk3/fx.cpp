// Roman Henson Coding 1 Spring 2026
// Functions!

// to compile, open Terminal
// navigate to this folder with 'cd' for 'change directory'
// use the command 'clang++ -o fx fx.cpp' to compile
// and then type './fx' to run the program

/* BLOCK COMMENT */

/*
    Functions
        returnType FunctionName (input parameters) { code }
    Sending and receiving variables to and from a function.
    Passing by value 
    Passing by reference
*/

#include <iostream>
#include <string>
#include <cstdlib>              // for rand() and srand()
#include <ctime>                // for time()
#include <vector>

using namespace std;


// declaring and defining a new function 
// the return type is void, which means it returns NOTHING
// the name of the function is "sayHello"
// the input parameters go in the parenthesis.... this function doesn't have any.
// then the code goes between {curly braces}!
// call this function in main by typing 'sayHello();'
void sayHello() {
    cout << "Hello!\n";
}

void doAddition(int firstNum = 2, int secondNum = 2) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "Together they make " << firstNum + secondNum << ".\n";
}

// don't forget to include <cstdlib> and <ctime>
// this function will return an integer!
int dieRoll(int sides = 6, int min = 1) {
    return rand() % sides + min;
}

// create a function
// return type is bool
// name is askYesNo
// no input parameters (for now)
bool askYesNo(string question = "Do you want to keep playing?") {
    while(true) {
        cout << question << " ('yes'/'no')\n";
        string input;
        getline(cin, input);

        if(input == "yes") {
            return true;            // this will break out of the entire function
        }
        else if(input == "no") {
            return false;           // this will break out of the entire function
        }
        else {
            cout << "I did not understand. Please type 'yes' or 'no'.\n";
        }
    }
}

// passing by reference lets us edit the original vector inside the function
// create a reference with an ampersand next to the variable type: vector<string>&

void showVec(vector<string>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

// references let us edit the original.
void addStringToVec(vector<string>& vec) {
    cout << "What name would you like to add?\n";
    string input;
    getline(cin, input);

    vec.push_back(input);
}

int main() {
    srand(time(0));                         // seed the random number generator
    vector<string> names = {"Finn", "Jake", "Marceline", "BMO", "Princess Bubblegum"};

    // calling the showVec() function and sending it our vector of names.
    showVec(names);

    addStringToVec(names);      // add a string to our names vector

    showVec(names);             // the new name should now appear

    cout << "Finally, functions!\n";

    sayHello(); 

    doAddition();

    cout << "let's roll the dice! Our first number is " << dieRoll(6) << ".\n";

    doAddition(dieRoll(20), dieRoll(20));
    doAddition(dieRoll(), dieRoll(222));

    // call the askYesNo() function, and it will return true or false.
    if(askYesNo()) {
        cout << "Let's start the next level!\n";
    }
    else {
        cout << "Thanks for playing!\n";
        return 0;
    }

    // call the askYesNo() function, and it will return true or false.
    if(askYesNo("Do you like watermelons?")) {
        cout << "hey, yeah, they're really yummy!\n";
    }
    else {
        cout << "Right? Me too, it's a texture thing!\n";
    }
    

    return 0;
}

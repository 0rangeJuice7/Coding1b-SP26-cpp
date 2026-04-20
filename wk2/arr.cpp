// Roman Henson Coding 1 Spring 2026

// to compile, open Terminal
// navigate to this folder with 'cd' for 'change directory'
// use the command 'clang++ -o arr arr.cpp' to compile
// and then type './main' to run the program

// Arrays, Loops, and Vectors
    // for and foreach loops
    // algorithms?

#include <iostream>
#include <string>
#include <cstdlib>          // for rand() and srand()
#include <ctime>            // for time()

using namespace std;

int main() {
    srand(time(0));

    cout << "Let's make some arrays!\n";

    // arrays cannot change their size
    // arrays dont know where the "last index" is
    // arrays are a list of similar variable type
    // arrays are ordered

    // this is creating an integer array with a size of 5
    int scores[5];      

    scores[0] = 4545;
    scores[1] = 13;
    scores[2] = 9001;
    scores[3] = 2456;
    scores[4] = -4;
    // scores[5] = 99999; // can't go past the size of the array

    cout << "The first score is " << scores[0] << ".\n";

    cout << "Here are all of the scores:\n";

    int index = 0;
    while(index < 5) {
        cout << scores[index] << "\n";
        index++;
    }

    cout << "Using a for loop:\n";
    // for loop has the 'iterator' built in.
    // for(setup; test; action)
    for(int i = 0; i < 5; i++) {
        cout << scores[i] << "\n";
    }

    // let's build a string array for names
    string names[10];
    string input;
    index = 0;      //reset index so that we can use it again
    
    // keep looping until the array is full
    while(index < 10) {
        // we want the user to add names to the array
        cout << "type name, or 'done': ";
        cin >> input;
        
        // until they type 'done' 
        if(input == "done") {
            cout << "Done adding names.\n";
            break;          // stop looping.
        }

        // add the name to the array
        // then add 1 to index with the increment operator
        names[index++] = input;
        
    }

    // show the list of names
    for(int i = 0; i < 10; i++) {
        if(names[i] == "") {
            continue;           // start the loop over early.
        }

        cout << names[i] << "\n";
    }

    // create a new string array
    // initializing the array with values.
    string newNames[] = {"Mario", "Luigi", "Peach", 
                            "Captain Toad", "Bowser", "Rosalina", 
                            "Yoshi", "Bowser Jr."
                        };

    cout << "Here are the new names:\n";
    for(int i = 0; i < 8; i++) {
        cout << i + 1 << ". " << newNames[i] << "\n";
    }

    // pick a random name from our newNames array
    int randIndex = rand() % 8;
    string character = newNames[randIndex];

    cout << character << ", let's talk about them.\n";

    // an enumerator is a custom variable type
    // with only the values that we specify
    // they correspond to numbers, starting with 0 by default.
    enum favor {LOVE, LIKE, DISLIKE, LOATHE};
    enum difficulty {EASY, NORMAL, HARD, IMPOSSIBLE};
    enum shirtSize {EXTRA_SMALL, SMALL, MEDIUM, LARGE, EXTRA_LARGE};

    switch(rand() % 4) {
        case LOVE:
            cout << "I love " << character << ".\n";
            break;
        case LIKE:
            cout << "I like " << character << ".\n";
            break;
        case DISLIKE:
            cout << "I dislike " << character << ".\n";
            break;
        case LOATHE:
            cout << "I loathe " << character << ".\n";
            break;
    }


    return 0;
}
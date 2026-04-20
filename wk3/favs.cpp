// Roman Henson Coding 1 Spring 2026
// Game List Manager

// to compile, open Terminal
// navigate to this folder with 'cd' for 'change directory'
// use the command 'clang++ -o favs favs.cpp' to compile
// and then type './favs' to run the program

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // the games vector lives here, OUTSIDE the loop
    // so it persists between commands
    vector<string> games;

    while(true) {
        cout << "What would you like to do?\n";
        cout << "You can 'add', 'edit', 'remove', 'show', or 'quit'.\n";

        string input;
        getline(cin, input);

        if(input == "quit") {
            cout << "Thanks for playing.\n";
            break;
        }
        else if(input == "add") {
            // TODO: ask for a game name and push_back into games
        }
        else if(input == "edit") {
            // TODO: show games, ask which to edit, replace it
        }
        else if(input == "remove") {
            // TODO: show games, ask which to remove, erase it
        }
        else if(input == "show") {
            // TODO: sort games and print each one
        }
        else {
            cout << "I don't recognize that input.\n";
        }
    }
}

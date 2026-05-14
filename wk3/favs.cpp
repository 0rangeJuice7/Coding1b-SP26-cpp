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
            cout << "What is the game name? ";
            string gameName;
            getline(cin, gameName);
            games.push_back(gameName);
        }
        else if(input == "edit") {
            sort(games.begin(), games.end());
            for(int i = 0; i < games.size(); i++) {
                cout << i + 1 << ". " << games[i] << "\n";
            }
            cout << "What number would you like to edit? \n";
            int choice;
            cin >> choice;
            cin.ignore();
            if(choice >= 1 && choice <= games.size()) {
                cout << "What is the new name? \n";
                string newName;
                getline(cin, newName);
                games[choice - 1] = newName;
                cout << "Game updated.\n";
            }
            else {
                cout << "That number is not on the list.\n";
            }
        }
        else if(input == "remove") {
            //TODO: remove games, asks for which number, removes
            sort(games.begin(), games.end());
            for(int i = 0; i < games.size(); i++) {
                cout << i + 1 << ". " << games[i] << "\n";
            }
            cout << "What number would you like to remove? \n";
            int choice;
            cin >> choice;
            cin.ignore();
            if(choice >= 1 && choice <= games.size()) {
                games.erase(games.begin() + choice - 1);
                cout << "Game removed.\n";
            }
            else {
                cout << "That number is not on the list.\n";
            }
        }
        else if(input == "show") {
            // TODO: sort games and print each one
            sort(games.begin(), games.end());
            for(int i = 0; i < games.size(); i++) {
                cout << i + 1 << ". " << games[i] << "\n";
            }
        }
        else {
            cout << "I don't recognize that input.\n";
        }
    }
}

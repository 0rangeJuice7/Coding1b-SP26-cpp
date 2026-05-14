// Roman Henson Coding 1 Spring 2026
// Functions Prep
 
// to compile, open Terminal
// navigate to this folder with 'cd' for 'change directory'
// use the command 'clang++ -o fxprep fxprep.cpp' to compile
// and then type './fxprep' to run the program
 

#include <string>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct bot {
    int charge;
    string name;
};


void hello() {
    cout << "Hello.\n";
}

// function overloading
void hello(string name) {
    cout << "Hello " << name << ".\n";
}

int add(int x, int y) {
    return x + y;
}

string addSpaces(string input) {
    string temp;
    // for(char c : input) {
    //     temp += (c + ' ');
    // }

    cout << "debugging.\n";
    cout << "input[0] = " << input[0] << ".\n";

    for(int i = 0; i < input.size(); i++) {
        temp += input[i];
        temp += " ";
    }

    return temp;
}

void showArray(string* array, int size) {
    for(int i = 0; i < size; i++) {
        if(array[i] == "") continue;
        cout << array[i] << endl;
    }
}

int dieRoll(int sides = 6) {
    return rand() % sides + 1;
}

int main () {
    srand(time(0));
    cout << "Finally, Functions!\n";

    hello();

    bot artoo;
    artoo.charge = 10;
    artoo.name = "R2-D2";

    // sending variables
    hello("Brian");
    // returning variables
    int sum = add(2,2);
    string coolWord = addSpaces("aesthetic");
    cout << coolWord << ".\n";
    // sending arrays and vectors.
    string words[10] = {"Walk", "All ", "Over", "You"};
    
    showArray(words, 10);

    cout << "let's see what sort of day we're going to have!\n";

    if(dieRoll(20) > 10) {
        cout << "it'll be a good day!\n";
    } else {
        cout << "well, we'll see.\n";
    }


    // 1. The Seeder: Get a truly random hardware seed from the OS
    random_device rd;

    // 2. The Engine: Initialize the Mersenne Twister PRNG with the seed
    mt19937 gen(rd());

    // 3. The Distribution: Define your desired range (inclusive)
    // For example, calculating a sword swing damage between 15 and 25
    uniform_int_distribution<int> damage_dist(15, 25);

    cout << "Player attacks for 3 hits!\n";
    for (int i = 0; i < 33; ++i) {
        // Generate the random number by passing the engine to the distribution
        int damage = damage_dist(gen);
        cout << "Hit " << i + 1 << ": " << damage << " damage.\n";
    }


    return 0;
}
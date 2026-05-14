// Roman Henson Coding 1 Spring 2026
// Classes, Getters, and Setters
 
// to compile, open Terminal
// navigate to this folder with 'cd' for 'change directory'
// use the command 'clang++ -o main main.cpp' to compile
// and then type './main' to run the program


#include <iostream>
#include <string>
using namespace std;

// classes are custom variables types that have their own
// variables and functions

// constructors
// getters and setters (privacy)
// instances
// inheritance (not today though)

// this is my new variable type.
class robot {
private:
    // data members
    string name;
    int charge;
    int boredom;

public:
    // a constructor accepts variables and sets up the robot when it is created.
    // a constructor function needs no return type, and must be named same as class
    robot(string givenName, int givenCharge, int givenBoredom) {
        name = givenName;
        charge = givenCharge;
        boredom = givenBoredom;
        status();
    }

    // overload the constructor
    robot() {
        name = "bot";
        charge = 10;
        boredom = 0;
        status();
    }

    // member functions
    void status() {
        cout << "My name is " << name << ", my charge is " << charge << ".\n";
        cout << "I am ";
        
        if(boredom < 5) {
            cout << "happy";
        }
        else if(boredom < 10) {
            cout << "bored";
        }
        else if(boredom < 15) {
            cout << "frustrated";
        }
        else {
            cout << "ENRAGED";
        }

        cout << ".\n";
    }

    void newDay() {
        boredom += 2;
    }

    void play() {
        boredom -= 1;
    }

    // setter
    void setName(string givenName) {
        if(givenName.size() <= 5) {
            name = givenName;
        }
        else {
            cout << "error: name is too long.\n";
        }
    }

    void setCharge(int givenCharge) {
        if(givenCharge < 0) {           // clamping value to not lower than 0
            charge = 0;
        }
        else if(givenCharge > 100) {    // clamping not higher than 100
            charge = 100;
        }
        else {
            charge = givenCharge;
        }
    }

    // combined get AND set, using the clamping from setCharge.
    void changeCharge(int amount) {
        setCharge(charge += amount);
    }

    // getters
    string getName() {
        return name;
    }
    int getCharge() {
        return charge;
    }
    int getBoredom() {
        return boredom;
    }

};                  // don't forget the semi-colon at the end
                    // of the class definition



int main() {
    cout << "let's build some classes!\n";

    // creating two new variables of the type 'robot'
    robot artoo("R2-D2", 45, 10);       // using the constructor
    // artoo.name = "R2-D2";
    // artoo.charge = 45;
    // artoo.boredom = 10;

    robot threepio;
    threepio.setName("C-3PO");        // using the setter now!
    threepio.setCharge(2);

    cout << "Here's artoo: " << artoo.getName() << ".\n";

    cout << artoo.getName() << " notices that " << threepio.getName();
    cout << " doesn't have much battery left. Let's fix that.\n";

    while(threepio.getCharge() < 15) {
        artoo.changeCharge(-1);          // subtract 1 from charge
        threepio.changeCharge(1);       // add 1 to charge.
    }

    cout << "threepio's charge is now " << threepio.getCharge() << ".\n";
    cout << "artoo's charge is now " << artoo.getCharge() << ".\n";


    // using member functions
    artoo.status();
    threepio.status();

    string input = "";
    int turns = 0;

    while(true) {
        while(turns < 3) {
            cout << "what would you like to do?\n";
            getline(cin, input);

            if(input == "play") {
                cout << "let's play with " << artoo.getName() << "!\n";
                artoo.play();
            }
            else if(input == "status") {
                artoo.status();                 // TODO: add boredom to status.
            }
            turns++;
        }
        turns = 0;
        cout << "Do you want to keep playing?\n";
        getline(cin, input);
        
        if(input == "no") {
            break;
        }
        artoo.newDay();
    }

    return 0;
}
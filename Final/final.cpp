// Roman Henson Coding 1 Spring 2026
// Critter Final

// to compile, open Terminal
// navigate to this folder with 'cd' for 'change directory'
// use the command 'clang++ -o final final.cpp' to compile
// and then type './final' to run the program

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Critter {
private:
    string name;
    int health;
    int damage;
    int hunger;

public:
    Critter(string givenName) {
        name = givenName;
        health = 20;
        damage = 5;
        hunger = 0;
    }

    // setters
    void setName(string givenName) { name = givenName; }
    void setHealth(int givenHealth) { health = givenHealth; }
    void setDamage(int givenDamage) { damage = givenDamage; }
    void setHunger(int givenHunger) { hunger = givenHunger; }

    // getters
    string getName() { return name; }
    int getHealth() { return health; }
    int getDamage() { return damage; }
    int getHunger() { return hunger; }

    void hello() {
        cout << "Name: " << name << "\n";
        cout << "Health: " << health << "\n";
        cout << "Damage: " << damage << "\n";
        cout << "Hunger: " << hunger << "\n";
    }

    void feed() {
        hunger = 0;
        cout << name << " has been fed!\n";
    }

    void train() {
        if(hunger > 10) {
            cout << name << " is too hungry to train! Feed them first.\n";
            return;
        }
        if(hunger > 5) {
            cout << name << " is hungry but will train anyway...\n";
        }

        hunger++;

        if(rand() % 2 == 0) {
            health += 2;
            cout << name << " trained hard! Health increased to " << health << ".\n";
        }
        else {
            damage += 1;
            cout << name << " trained hard! Damage increased to " << damage << ".\n";
        }
    }

    void battle(Critter& opponent) {
        if(hunger > 10) {
            cout << name << " is too hungry to battle! Feed them first.\n";
            return;
        }
        if(hunger > 5) {
            cout << name << " is hungry but will battle anyway...\n";
        }

        hunger++;

        cout << "A wild " << opponent.getName() << " appears!\n";

        while(health > 0 && opponent.getHealth() > 0) {
            cout << "\nWhat will you do?\n";
            cout << "attack, heal, or run\n";

            string input;
            getline(cin, input);

            if(input == "attack") {
                opponent.setHealth(opponent.getHealth() - damage);
                cout << name << " attacks " << opponent.getName() << " for " << damage << " damage!\n";
                cout << opponent.getName() << " has " << opponent.getHealth() << " health left.\n";

                if(opponent.getHealth() <= 0) {
                    cout << opponent.getName() << " has been defeated!\n";
                    break;
                }

                // opponent attacks back
                health -= opponent.getDamage();
                cout << opponent.getName() << " attacks back for " << opponent.getDamage() << " damage!\n";
                cout << name << " has " << health << " health left.\n";

                if(health <= 0) {
                    cout << name << " has been defeated!\n";
                }
            }
            else if(input == "heal") {
                health += 5;
                cout << name << " heals for 5 health! Now at " << health << ".\n";
            }
            else if(input == "run") {
                cout << name << " ran away!\n";
                break;
            }
        }
    }
};

int main() {
    srand(time(0));

    // read names from file
    vector<string> names;
    ifstream file("names.txt");
    string line;
    while(getline(file, line)) {
        names.push_back(line);
    }
    file.close();

    // pick a random name
    string randomName = names[rand() % names.size()];

    // let the player name their critter
    cout << "Welcome! Your critter's suggested name is " << randomName << ".\n";
    cout << "What would you like to name your critter? ";
    string playerName;
    getline(cin, playerName);

    // create the critter
    Critter myCritter(playerName);

    // create a wild opponent critter with random name
    Critter wildCritter(names[rand() % names.size()]);
    wildCritter.setDamage(rand() % 5 + 3);

    // main loop
    while(true) {
        cout << "\nWhat would you like to do?\n";
        cout << "feed, train, inspect, battle, or quit\n";

        string input;
        getline(cin, input);

        if(input == "quit") {
            cout << "Goodbye!\n";
            break;
        }
        else if(input == "feed") {
            myCritter.feed();
        }
        else if(input == "train") {
            myCritter.train();
        }
        else if(input == "inspect") {
            myCritter.hello();
        }
        else if(input == "battle") {
            myCritter.battle(wildCritter);
        }
        else {
            cout << "I don't recognize that command.\n";
        }
    }

    return 0;
}

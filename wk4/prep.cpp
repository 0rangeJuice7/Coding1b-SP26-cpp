// Roman Henson Coding 1 Spring 2026
// File Streams - Reading and Writing
 
// to compile, open Terminal
// navigate to this folder with 'cd' for 'change directory'
// use the command 'clang++ -o prep prep.cpp' to compile
// and then type './prep' to run the program
 

#include <iostream>
#include <fstream>      // file stream
#include <istream>
#include <ostream>
using namespace std;

// move those functions to a header file
// read from file
// write to file
void writeToFile(string path = "output.txt") {
    fstream file(path);
    file.open(path);

    file << "files can be tricky, but it is fun.\n";

    string text;
    getline(file, text);
    cout << text << "\n";

    file.close();
}

int main() {

    if(true) {
        cerr << "this is an error." << "\n";
        return 1;
    }

    cout << "let's build some things.\n";

    string text = "here is some text";

    ofstream file;
    file.open("save.txt");
    file << text;
    file.close();

    string line;
    ifstream readFile("save.txt");
    if(readFile.is_open()) {
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "Cannot read from that file.\n";
    }

    readFile.close();

    return 0;
}
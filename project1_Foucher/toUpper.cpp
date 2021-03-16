// CS1300 Spring 2020
// Author: Mathieu Foucher
// Recitation: 301 - Telly Umada
// Project 1 - Problem #3

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// This is the toUpper function.
string toUpper(string orig){
    int length = orig.length();
    string newString;

    // The "for" loop below scans the string for any lowercase english letters, if a character in the string is one of these
    // letters, the if statement inside will cast the character as an INT in ASCII values and compute the capital version.
    for(int i; i < length; i++){
        if((int)orig[i] < 123 && (int)orig[i] > 96){
            int index = (int)orig[i] - 32;
            orig[i] = (char)index;
        }
    }
    //newString = orig;
    return orig;
}


// The main function here only has the toUpper function take an input and give an output.
int main(){

    string input;

    cout << "Enter the string: " << endl;
    getline(cin, input);

    string upperCase = toUpper(input);

    cout << upperCase << endl;

    return 0;
}
// CS1300 Spring 2020
// Author: Mathieu Foucher
// Recitation: 301 - Telly Umada
// Project 1 - Problem #1

#include <iostream>
#include <cmath>

using namespace std;

// This is the pyramid area function.
double surfaceArea(double baseLength, double slantHeight){
    if(baseLength >= 0 && slantHeight >= 0){
        double surfaceAreaValue = ((baseLength*slantHeight)/(2.0))*4.0 + pow(baseLength,2.0);
        return surfaceAreaValue;
    } else {
        return -1;
    }
} 

int main(){
    double in1;
    double in2;

    cout << "Enter the base length: " << endl;
    cin >> in1;
    cout << "Enter the slant height: " << endl;
    cin >> in2;

    double area = surfaceArea(in1 , in2);

    if(area == -1){
        cout << "Invalid values" << endl;
    } else {
        cout << "The surface area: " << area << endl;
    }




    return 0;
}
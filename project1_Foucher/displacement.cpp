// CS1300 Spring 2020
// Author: Mathieu Foucher
// Recitation: 301 - Telly Umada
// Project 1 - Problem #2

#include <iostream>
#include <cmath>

using namespace std;

double displacementFunc(double initialVel, double finalVel , double decel){
    
    // Each of the "if" loops will validate the different inputs.
    if(initialVel < 0 || finalVel < 0){
        cout << "Velocity should be greater than zero." << endl;
    }

    if(decel < 0){
        cout << "The vehicle is speeding up." << endl;
    }
    
    if(decel == 0){
        cout << "No brakes were applied" << endl;
    }
    if(finalVel > initialVel){
        cout << "Error in acceleration values." << endl;
        return 0;
    } 
    // Here is the actual computation of the displacement function with the given inputs.
    if((decel > 0 && finalVel <= initialVel) && (initialVel >= 0 && finalVel >= 0)){
        double displacementValue = (pow(finalVel, 2.0) - pow(initialVel , 2.0))/((-2.0)*decel);
        return displacementValue;
    } 
    

return 0;    
}

int main(){

    double iv;
    double fv;
    double dc;

    cout << "Enter initial velocity: " << endl;
    cin >> iv;
    cout << "Enter final velocity: " << endl;
    cin >> fv;
    cout << "Enter deceleration: " << endl;
    cin >> dc;

    double displacement = displacementFunc(iv,fv,dc);

    if(displacement != 0){
    cout << "Displacement is " << displacement << endl;
    }



    return 0;
}
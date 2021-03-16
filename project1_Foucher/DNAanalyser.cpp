//CS1300 Spring 2020
//Author: Mathieu Foucher
//Recitation: 301 - Telly Umada
//Project 1 - Problem #7

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* The calcSimscore function takes in two strings
the output of this function is a double which is computed 
by comparing each charater in the inputs with eachother inside of
a for loop. Inside of the for loop there is an if statement that
has a int variable called "match" which will count how many instances 
two characters are the same in the string inputs. The result is this match value
divided by the length of the sequence inputs (we only need to divide by one input length
since both inputs must be the same length). The simScore is returned as a double.
*/
double calcSimScore(string sequence1, string sequence2){
    double simScore = 0.0;
    double match = 0.0;

    if(sequence1 == "" || sequence2 == ""){
        return 0;
    }

    if(sequence1.length() > sequence2.length() || sequence1.length() < sequence2.length()){
        simScore = 0;
    } else {
        match = 0.0;
        for(int i = 0; i < sequence1.length(); i++){
            if(sequence1[i] == sequence2[i]){
                match = match+1;
            }
        }
        simScore = (match)/(sequence1.length());
    }
    return simScore;
}

/* findBestSimScore is another function that will find the best similarity score from a genome
of arbitrary length and a sequence of length 3. How this function calculates the best score
is by extracting all substrings of length 3 from the genome. The function that is used to calculate
the similarity scores for the substrings extracted is the calcSimScore function. Lastly, a while
loop and a double variable "largest" are used to find the highest similarity score from all substrings.
*/
double findBestSimScore(string genome, string sequence){
    string genomeSub = "";
    double simScore = 0.0;
    double largest = 0.0;

    for(int i = 0; i < genome.length(); i++){
        genomeSub = genome.substr(i, sequence.length());
        simScore = calcSimScore(genomeSub, sequence);
        if(simScore > largest){
            largest = simScore;
        }
    }

    simScore = largest;

    return simScore;
}

/* findMatchedGenome is the function that will take three genomes, one sequence, and compute
the best similarity scores from each genome to find which genome is the best match. This function
depends on the function findBestSimScore which in turn depends on calcSimScore. In order to find
the best score, we take the bbest similarity score from all three of the genomes. Once this is done
an array called "sims" is used to store the three similarity scores. There is then a for loop
whos purpose is to find the largest genome sim score from the array. The last if loop
will print which genomes are the best match from this process described.
*/
void findMatchedGenome(string genome1, string genome2, string genome3, string sequence){

    using namespace std;
    double sim1 = 0.0;
    double sim2 = 0.0;
    double sim3 = 0.0;
    int lengths = genome1.length() + genome2.length() + genome3.length();
    double largest = 0.0;
    int index;

    if((genome1 == "" || sequence == "") || (genome2 == "" || genome3 == "")){
        cout << "Genome or sequence is empty." << endl;
    } else if(lengths % genome1.length() != 0){
        cout << "Lengths of genomes are different." << endl;
    } else {

        sim1 = findBestSimScore(genome1 , sequence);
        sim2 = findBestSimScore(genome2 , sequence);
        sim3 = findBestSimScore(genome3 , sequence);

        double sims[3] = {sim1 , sim2 , sim3 };
        index = 0;

        for(int j =0; j < 3; j++){
            for(int i = 0; i < 3; i++){
                if(sims[i] > largest){
                    largest = sims[i];
                }
            }
            if(sims[j] >= largest){
                cout << "Genome " << j + 1 << " is the best match." << endl;
            }
        }
}
}

int main(){

    // These variables are for the function of the menu.
    int option;
    bool menuIndex = true;
    
    // Here are the inputs, they are organized in the categories of their options.

    // Option 1:
    string seq1;
    string seq2;

    // Option 2:
    string gen;
    string seq3;

    // Option 3:
    string gen1;
    string gen2;
    string gen3;
    string seq4;

    // The actual menu runs inside of this while loop when the bool menuIndex is true.

    while(menuIndex == true){
    cout << "Select a numerical option: " << endl;
    cout << "=== menu ===" << endl;
    cout << "1: Find similarity score " << endl;
    cout << "2: Find the best similarity score " << endl;
    cout << "3: Analyze the genome sequences " << endl;
    cout << "4: Quit " << endl;
    cin >> option;

    // Loop to validate inputs.
    if(option > 4 || option < 1){
        cout << "Invalid option." << endl;
        menuIndex = true;
    }

    // The following three "if" loops are what the menu will execute when the correct option is selected.
    if(option == 1){
        
        cout << "Enter sequence 1: " << endl;
        cin >> seq1;
        cout << "Enter sequence 2: " << endl;
        cin >> seq2;

        cout << "Similarity score: " << calcSimScore(seq1 , seq2) << endl;

        menuIndex = true;
    }
    
    if(option == 2){

        cout << "Enter the genome: " << endl;
        cin >> gen;
        cout << "Enter sequence: " << endl;
        cin >> seq3;

        cout << "Best similarity score: " << findBestSimScore(gen , seq3) << endl;
        
        menuIndex = true;
    }

    if(option == 3){

        cout << "Enter genome 1: " << endl;
        cin >> gen1;
        cout << "Enter genome 2: " << endl;
        cin >> gen2;
        cout << "Enter genome 3: " << endl;
        cin >> gen3;
        cout << "Enter sequence: " << endl;
        cin >> seq4;

        findMatchedGenome(gen1 , gen2 , gen3 , seq4);
        
        menuIndex = true;
    }

    // This last "if" loop is for the quit option, which closes the menu and ends the program.
    if(option == 4){
        cout << "Good bye!" << endl;
        menuIndex = false;
    }

    }



    return 0;
}
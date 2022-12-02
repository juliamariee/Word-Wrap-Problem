#include <vector>
#include "problem.h"
#include "solution.h"
#include "greedy.cpp"
#include "dp.cpp"
#include <fstream> 
#include <string>
#include <iostream>

int main (int argc, char *argv[]) { 
    // if we havent been given 3 inputs, format is incorrect
    if(argc != 4){
        cout << "Format Incorrect!" << endl;
        return -1;
    }

    ifstream inFile; // input file
    ofstream outFile; // output file

    inFile.open(argv[1]); // use the first command line arg as input file
    outFile.open(argv[2]); // use the second command line arg as output file
    int method = stoi(argv[3]); // use the third command line arg to select algorithm
    if(!outFile) cout << "output.txt not created"<< endl;
    int lineWidth = -1;
    string line = "";
    vector<int> words;

    // parse input
    string word_s = "";
    string lineWidth_s = "";
    if(inFile.is_open() && inFile.good()){
        inFile >> lineWidth_s;
        lineWidth = stoi(lineWidth_s);
        while(inFile >> word_s){ 
            words.push_back(stoi(word_s));
        }
    }
    // close the input file
    inFile.close();

    // create a problem with the input
    Problem problem(lineWidth, words);

    // declare the solution
    Solution solution;

    // switch over the method (3rd command line arg) to run the correct algorithm
    switch(method){
        case 0: //Greedy
            solution = greedy(problem);
            break;
        case 1: //DP
            solution = dp(problem);
            break;
        default:
            // error if third command line arg was not a 0 or 1
            cout << "Error" << endl;
            break;
    }

    // output the solution to the output file
    solution.show(outFile);    

    // close the output file
    outFile.close();
    return 0;
}

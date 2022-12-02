#include <vector>
#include "problem.h"
#include "solution.h"
#include "greedy.cpp"
#include "dp.cpp"
#include <fstream> 
#include <string>
#include <iostream>

int main (int argc, char *argv[]) { 
    if(argc != 4){
        cout << "Format Incorrect!" << endl;
        return -1;
    }

    ifstream inFile; //input file
    ofstream outFile; //output file

    inFile.open(argv[1]);
    outFile.open(argv[2]);
    int method = stoi(argv[3]);
    if(!outFile) cout << "output.txt not created"<< endl;
    int lineWidth = -1;
    string line = "";
    vector<int> words;

    //Input Stuff
    string word_s = "";
    string lineWidth_s = "";
    if(inFile.is_open() && inFile.good()){
        inFile >> lineWidth_s;
        lineWidth = stoi(lineWidth_s);
        while(inFile >> word_s){ 
            words.push_back(stoi(word_s));
        }
    }
    inFile.close();

    Problem problem(lineWidth, words);

    Solution solution;
    switch(method){
        case 0: //Greedy
            solution = greedy(problem);
            break;
        case 1: //DP
            solution = dp(problem);
            break;
        default:
            cout << "Error" << endl;
            break;
    }
    solution.show(outFile);    

    outFile.close();
    return 0;
}

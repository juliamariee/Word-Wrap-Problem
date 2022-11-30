#include <vector>
#include "greedy.cpp"
#include "problem.h"
#include "solution.h"
#include "dp.cpp"
#include <fstream> 
#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>

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
    if(inFile.is_open() && inFile.good()){
        inFile >> std::int >> lineWidth;
        while(inFile >> std::int >> word){
            words.push_back(word);
        }
    }
    inFile.close();

    Problem problem(lineWidth, words);

    return 0;
}
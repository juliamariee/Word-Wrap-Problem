#include <vector>
#include <fstream> 
#include <string>
#include <iostream>

using namespace std;
int main (int argc, char *argv[]) { 
    if(argc != 4){
        cout << "Format Incorrect!" << endl;
        return -1;
    }

    ifstream inFile; //input file
    ofstream outFile; //output file

    inFile.open(argv[1]);
    outFile.open(argv[2]);
    if(!outFile) cout << "output.txt not created"<< endl;
    string line = "";

    //Input Stuff
    string word_s = "";
    if(inFile.is_open() && inFile.good()){
        outFile << argv[3] << endl;
        while(inFile >> word_s){ 
          outFile << word_s.length() << " ";
        }
    }
    inFile.close();
    return 0;
}

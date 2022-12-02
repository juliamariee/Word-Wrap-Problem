#include <vector>
#include <fstream> 
#include <string>
#include <iostream>
#include <math.h>

using namespace std;
int main (int argc, char *argv[]) { 
  //./exec start end step width
    if(argc != 5){
        cout << "Format Incorrect!" << endl;
        return -1;
    }

    ofstream outFile; //output file
    int start = stoi(argv[1]);
    int end = stoi(argv[2]);
    int step = stoi(argv[3]);
    int width = stoi(argv[4]);

    for (int i = start; i < end; i += step) {
      string file = "./goCrazy/test_" + to_string(i) + "_" + to_string(width);
      outFile.open(file);
      outFile << width << endl;
      for (int j = 1; j < i; j++) {
        outFile << rand() % width+1 << " ";
      }
      outFile.close();
    }

    outFile.open(argv[2]);
    if(!outFile) cout << "output.txt not created"<< endl;
    string line = "";

    //Input Stuff
    string word_s = "";
    return 0;
}

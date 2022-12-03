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

    for (int i = start; i <= end; i += step) {
      string file = "goCrazy/test_" + to_string(i) + "_" + to_string(width)+".txt";
      //string file = "test_" + to_string(i) + "_" + to_string(width)+".txt";
      outFile.open(file);
      outFile << width << endl;
      for (int j = 1; j < i; j++) {
        outFile << rand() % width+1 << " ";
      }
      outFile.close();
    }

    return 0;
}

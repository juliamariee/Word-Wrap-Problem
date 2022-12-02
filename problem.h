#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>

using namespace std;

// header file for problem class
class Problem{
    public:
        int lineWidth; // max line width for the problem
        vector<int> words; // vector of ints or "words" of the problem
        Problem(int gLineWidth, vector<int> gWords); // constructor for problem class 
        Problem(); // empty constructor for problem class 
};

#endif
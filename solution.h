#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include <fstream>

using namespace std;

// header file for solution class
class Solution{
    public:
        int lineWidth; // max line width of the solution
        vector< vector<int> > lines; // contains all of the lines that make up the solution
        float cost; // cost of the solution
        int time; // time the solution took
        Solution(); // empty constructor for a solution
        void show(ofstream& out); // show method for a solution, writes to an output file
        void calculateCost(); // calculates the cost for the solution
    
};

#endif

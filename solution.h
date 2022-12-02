#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include <fstream>

using namespace std;

class Solution{
    public:
        int lineWidth;
        vector< vector<int> > lines;
        float cost;
        int time;
        Solution(int gLineWidth, vector<int> gWords, int gCost);
        Solution();
        void show(ofstream& out);
        void calculateCost();
    
};

#endif

#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>

using namespace std;

class Solution{
    public:
        int lineWidth;
        vector<vector<int>> lines;
        int cost;
        int time;
        Solution(int gLineWidth, vector<int> gWords, int gCost);
        Solution();
    
};

#endif
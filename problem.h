#ifndef PROBLEM_H
#define PROBLEM_H
#include <vector>

using namespace std;

class Problem{
    public:
        int lineWidth;
        vector<int> words;
        Problem(int gLineWidth, vector<int> words);

};

#endif
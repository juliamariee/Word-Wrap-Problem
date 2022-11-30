#ifndef GREEDY_H
#define GREEDY_H
#include <vector>
#include <cmath>
#include "solution.h"
#include "problem.h"

using namespace std;

Solution greedy(Problem problem) {
    vector<int> words = problem.words;
    int lineWidth = problem.lineWidth;
    Solution solution;
    solution.lineWidth = lineWidth;
    vector<int> currLine;
    int currWidth = 0;
    for(int i = 0; i < words.size(); i++) {
        if((currWidth + words[i]) < lineWidth) {
            currLine.push_back(words[i]);
        } else {
            solution.lines.push_back(currLine);
            currLine.clear();
            currLine.push_back(words[i]);
            currWidth = words[i];
        }
    }

    int totalCost  = 0;
    for(int i = 0; i < solution.lines.size(); i++) {
        int currlineLength = 0;
        for(int j = 0; j < solution.lines[i].size(); j++) {
            currlineLength += solution.lines[i][j];
        }
        totalCost += (lineWidth - currlineLength);
    }

    totalCost = pow(totalCost, 3);
    solution.cost = totalCost;
    return solution;
};

#endif
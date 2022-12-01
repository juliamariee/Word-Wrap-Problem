#include <vector>
#include <cmath>
#include <chrono>
#include <iostream>
#include "problem.h"
#include "solution.h"

using namespace std;

Solution greedy(Problem problem) {
    auto start = chrono::high_resolution_clock::now();
    vector<int> words = problem.words;
    int lineWidth = problem.lineWidth;
    Solution solution;
    solution.lineWidth = lineWidth;
    vector<int> currLine;
    int currWidth = 0;
    for(int i = 0; i < words.size(); i++) {
        if((currWidth + words[i]) < lineWidth) {
            currLine.push_back(words[i]);
            currWidth += words[i];
        } else {
            solution.lines.push_back(currLine);
            currLine.clear();
            currLine.push_back(words[i]);
            currWidth = words[i];
        }
    }
    if(currLine.size() > 0) {
        solution.lines.push_back(currLine);
    }
;
    auto end = chrono::high_resolution_clock::now();
    auto timePased = chrono::duration_cast<chrono::nanoseconds>(end - start);
    solution.time = timePased.count();
    solution.calculateCost();
    return solution;
};

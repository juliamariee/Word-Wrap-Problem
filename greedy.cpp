#include <vector>
#include <cmath>
#include <chrono>
#include <iostream>
#include "problem.h"
#include "solution.h"

using namespace std;

// given a problem, calculates the greedy solution
Solution greedy(Problem problem) {
    auto start = chrono::high_resolution_clock::now(); // start the clock for timing the solution
    vector<int> words = problem.words; // get the words for the problem 
    int lineWidth = problem.lineWidth; // get the max line width for the problem
    Solution solution; // make the solution, we'll populate this with the real solution
    solution.lineWidth = lineWidth; // set the solution line width to the problem line width
    vector<int> currLine; // make a vector to store the current line
    int currWidth = 0; 
    // loop over the words
    for(int i = 0; i < words.size(); i++) {
        if((currWidth + words[i]) == lineWidth) {
            // if the word fits perfectly, add the word to the current line
            currLine.push_back(words[i]);
            // add the current line to the solution
            solution.lines.push_back(currLine);
            // clear the current line
            currLine.clear();
            // set the current width back to 0
            currWidth = 0;
        } else if((currWidth + words[i] + 1) < lineWidth) {
            // if the word fits, add the word to the current line
            currLine.push_back(words[i]);
            // increase the current width by word length + 1 (to account for the spaces between the words)
            currWidth += words[i] + 1;
        } else {
            // if the word doesnt fit, add current line to the solutiojn
            solution.lines.push_back(currLine);
            // clear the current line
            currLine.clear();
            // add the word to the next current line
            currLine.push_back(words[i]);
            // set the length of current line equal to the word length
            currWidth = words[i];
        }
    }
    if(currLine.size() > 0) {
        // at the end if theres a line that hasnt been added to the solution yet, add it here
        solution.lines.push_back(currLine);
    }

    solution.calculateCost(); // calculate the cost of the solution
    auto end = chrono::high_resolution_clock::now(); // stop the clock
    auto timePased = chrono::duration_cast<chrono::nanoseconds>(end - start); // calculate time passed
    solution.time = timePased.count(); // set time passed to the solution time
    
    return solution; // return the solution
};

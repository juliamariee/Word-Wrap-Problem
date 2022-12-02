#include "solution.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

Solution::Solution() {} // empty constructor for the solution class

// show method for the solution class
// displays the words that make up the solution, cost of the solution, and time taken to execute
void Solution::show(ofstream& out) {
    int character = 0;
    // loops through the lines, prints out "words" in alphabetical order
    // ie. aaaa bb cc ddd ee ffffff ggg .... and so on
    for(int i = 0; i < lines.size(); i++) {
        for(int j = 0; j < lines[i].size(); j++) {
            for(int k = 0; k < lines[i][j]; k++) {
                out << (char)(character + 97);
            }
            character = (character + 1) % 26;
            out << " ";
        }
        out << endl;
    }
    out << "COST: " << to_string(cost) << endl; // outputs the cost of the solution
    out << "TIME ELAPSED: " << to_string(time * 10e-9) << " Seconds" << endl; // outputs time elapsed
}

// calculated the cost of a solution based on the lines of the solution
// we dont include the last line because that can heavily skew results
// its ok if the last line is relatively short because there were only a few words remaining
void Solution::calculateCost() {
    int totalCost  = 0;
    // loop through the lines (except the last line) and calculate the difference between the length of the line and the max length
    for(int i = 0; i < lines.size() - 1; i++) {
        int currlineLength = lines[i].size() - 1;
        for(int j = 0; j < lines[i].size(); j++) {
            currlineLength += lines[i][j];
        }
        // cube the difference and add to the total cost
        totalCost += (lineWidth - currlineLength) * (lineWidth - currlineLength) * (lineWidth - currlineLength);
    }
    // set the cost of the solution equal to totalCost
    cost = totalCost;

}
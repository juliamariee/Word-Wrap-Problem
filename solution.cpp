#include "solution.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

Solution::Solution() {}

void Solution::show(ofstream& out) {
    int character = 0;
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
    out << "COST: " << to_string(cost) << endl;
    out << "TIME ELAPSED: " << to_string(time * 10e-9) << " Seconds" << endl;
}

void Solution::calculateCost() {
    int totalCost  = 0;
    for(int i = 0; i < lines.size(); i++) {
        int currlineLength = lines[i].size() - 1;
        for(int j = 0; j < lines[i].size(); j++) {
            currlineLength += lines[i][j];
        }
        totalCost += (lineWidth - currlineLength) * (lineWidth - currlineLength) * (lineWidth - currlineLength);
    }
    cost = ((float) totalCost) / ((float) lines.size());
}
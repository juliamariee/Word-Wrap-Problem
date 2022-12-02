#include "problem.h"


Problem::Problem() {} // empty constructor for a problem

// constructor for a problem
// expects a line width, and a vector of ints or "words"
// creates a problem object with the given inputs
Problem::Problem(int gLineWidth, vector<int> gWords) {
    lineWidth = gLineWidth;
    words = gWords;
}
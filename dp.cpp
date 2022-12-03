#ifndef GREEDY_H
#define GREEDY_H
#include <stdint.h>
#include <vector>
#include "problem.h"
#include "solution.h"
#include <chrono>

using namespace std;

//Recursive function to populate our lines data structure to be able to print all the words 
int populateLines(vector< vector<int> > &lines, vector<int> words, int printList[], int numOfWords) {
  //Line number is useful for debugging
  int lineNumber;
  //if the current words is first then it must be the first line;
  if (printList[numOfWords] == 1) {
    lineNumber = 1;
  //Else recursively call until the first line is found using the next chunk of words
  } else {
    lineNumber = populateLines(lines, words, printList, printList[numOfWords]-1) + 1;
  }

  vector<int> currentLine;
  //Add all words between the current printList[numOfWords]-1 to num or words to to a temporary array to properly fill our vector 
  for (int i = printList[numOfWords]-1; i < numOfWords; i++) {
    currentLine.push_back(words[i]);
  }
  lines.push_back(currentLine);

  return lineNumber;
}

Solution dp(Problem problem) {
  //Start the clock for tracking time of execution
  auto start = chrono::high_resolution_clock::now();

  //Set problem variables to local variables for ease of use
  vector<int> words = problem.words;
  int lineWidth = problem.lineWidth;

  //Create solution
  Solution solution;
  solution.lineWidth = lineWidth;

  vector<int> currLine;

  //Create auxillary arrays for execution. Arrays will start at 1 to facillitate use, hence the +1;
  int extraSpace[words.size()+1][words.size()+1];
  int lineCost[words.size()+1][words.size()+1];
  int costTillNow[words.size()+1];
  int printList[words.size()+1];

  //Extra Space table
  //Fill auxilary table for the extra spaces on each line for a given configuration. Given words from words[i] to words[j] are placed on a single line, calculate extra space.
  for (int i = 1; i <= words.size(); i ++) {
    //Every diagonal is just the line width minus the lenght of the ith word
    extraSpace[i][i] = problem.lineWidth - words[i-1];
    //for every word after i fill the next slot in the table below it with the current extra spaces minus 1 more space minus the next word
    for (int j = i+1; j <= words.size(); j++) {
      extraSpace[i][j] = extraSpace[i][j-1] - words[j-1] - 1;
    }
  }

  //Line Cost table 
  //Fill line cost table. If extra space is less than 0 than the words in it form a line longer than the line width so it becomes infinity so it doesnt become part of the solution. If it is the last line, then it becomes 0 since the last line should not count against the solution. Else it cubes the extra space at the end of the line and that value becomes the value in the current spot
  //This top loop iterates through i
  for (int i = 1; i <= words.size(); i++) {

    //This nested loop iterates through j
    for (int j = i; j <= words.size(); j++) {
      //This checks if the extra space table is negative, if it is will set it to infinity
      if (extraSpace[i][j] < 0) {
        lineCost[i][j] = INT32_MAX;
      //Checks if its on the last word/line, if it is the cost is 0
      } else if (j == words.size() && extraSpace[i][j] >= 0) {
        lineCost[i][j] = 0;
      //Else it cubes the remaning space on the line for the cost
      } else {
        lineCost[i][j] = extraSpace[i][j]*extraSpace[i][j]*extraSpace[i][j];
      }
    }
  }

  //Final Cost table
  //costTillNow[j] is the optimal cost up until the jth word.
  //It finds the minimum cost of addign the next word into the output. It does this by finding constnatly comparing the cost of words that came before it to new possibilities and find the minimum cost of having j words.
  costTillNow[0] = 0;
  //Loops through every position in the array to fill it out
  for (int j = 1; j <= words.size(); j++) {
    //sets the temporary cost of the current j to infinity such that any solution is better
    costTillNow[j] = INT32_MAX;
    //Loops through all of the possibilities when inculding the next word
    for (int i = 1; i <= j; i ++) {
      //If the current proposed solution is a valid solution AND is better than the current solution than replace the cost with the new cost
      if (costTillNow[i-1] != INT32_MAX && lineCost[i][j] != INT32_MAX && (costTillNow[i-1] + lineCost[i][j] < costTillNow[j])) {
        costTillNow[j] = costTillNow[i-1] + lineCost[i][j];
        //Add i to print list printing later
        printList[j] = i;
      }
    }
  }


  vector< vector<int> > lines;
  populateLines(lines, words, printList, words.size());
  //Stop the clock
  auto end = chrono::high_resolution_clock::now();
  //Get the difference between start and end time
  auto timePased = chrono::duration_cast<chrono::nanoseconds>(end - start);

  //Finalize solution variables and use our solution object to calculate the final cost (it matches the one produced by our algorithm and made it easy to make it both contina the greedy and dp solution)
  solution.time = timePased.count();
  solution.lines = lines;
  solution.calculateCost();
  return solution;
};



#endif

#ifndef GREEDY_H
#define GREEDY_H
#include <stdint.h>
#include <vector>
#include "problem.h"
#include "solution.h"

using namespace std;

int populateLines(vector< vector<int> > &lines, vector<int> words, int printList[], int numOfWords) {
  int thing;
  if (printList[numOfWords] == 1) {
    thing = 1;
  } else {
    thing = populateLines(lines, words, printList, printList[numOfWords]-1) + 1;
  }
  vector<int> currentLine;
  for (int i = printList[numOfWords]-1; i < numOfWords; i++) {
    currentLine.push_back(words[i]);
  }
  lines.push_back(currentLine);
  return thing;

  
}

Solution dp(Problem problem) {
    vector<int> words = problem.words;
    int lineWidth = problem.lineWidth;
    Solution solution;
    solution.lineWidth = lineWidth;

    vector<int> currLine;

    int extraSpace[words.size()+1][words.size()+1];
    int lineCost[words.size()+1][words.size()+1];
    int costTillNow[words.size()+1];

    int printList[words.size()+1];

    for (int i = 1; i <= words.size(); i ++) {
      extraSpace[i][i] = problem.lineWidth - words[i-1];
      for (int j = i+1; j <= words.size(); j++) {
        extraSpace[i][j] = extraSpace[i][j-1] - words[j-1] - 1;
      }
    }

    for (int i = 1; i <= words.size(); i++) {
      for (int j = i; j <= words.size(); j++) {
        if (extraSpace[i][j] < 0) {
          lineCost[i][j] = INT32_MAX;
        } else if (j == words.size() && extraSpace[i][j] >= 0) {
          lineCost[i][j] = 0;
        } else {
          //lineCost[i][j] = extraSpace[i][j]*extraSpace[i][j]*extraSpace[i][j];
          lineCost[i][j] = extraSpace[i][j]*extraSpace[i][j];
        }
      }
    }

    costTillNow[0] = 0;
    for (int j = 1; j <= words.size(); j++) {
      costTillNow[j] = INT32_MAX;
      for (int i = 1; i <= j; i ++) {
        if (costTillNow[i-1] != INT32_MAX && lineCost[i][j] != INT32_MAX && (costTillNow[i-1] + lineCost[i][j] < costTillNow[j])) {
          costTillNow[j] = costTillNow[i-1] + lineCost[i][j];
          printList[j] = i;
        }
      }
    }


    vector< vector<int> > lines;
    populateLines(lines, words, printList, words.size());
    solution.lines = lines;
    return solution;
      
};



#endif

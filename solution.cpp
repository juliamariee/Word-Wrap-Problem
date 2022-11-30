#include "solution.h"
#include <stdio.h>
#include <iostream>

Solution::Solution() {}

void Solution::show() {
    int character = 0;
    for(int i = 0; i < lines.size(); i++) {
        for(int j = 0; j < lines[i].size(); j++) {
            for(int k = 0; k < lines[i][j]; k++) {
                cout << (char)(character + 97);
            }
            character = (character + 1) % 26;
            cout << " ";
        }
        cout << endl;
    }
}
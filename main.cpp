//
//  main.cpp
//  8 Queens
//
//  Created by Allen Moody on 8/29/14.
//  Copyright (c) 2014 FAMU. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

const int pSize = 8;   // can change to 4 for early testing
int queens[pSize];
int workingQueen = 0;


// return true if latest queen does not share a diagonal with any previous
//  else return false
bool checkDiag(int soFar) {
    // your code here
  
    
        
    
    for (int i=0; i<soFar; i++) {
        if(( abs(queens[soFar]-queens[i]) == abs(soFar-i)))
           
        return false;
    }
    return true;
    
}


// return false if latest queen column matches any earlier one
//    else return true
bool checkCols(int soFar) {
    // your code here
   
    for (int j = 0; j<soFar; j++) {
        if(queens[j] == queens[soFar])
            {
            return false;
            }
    }
    return true;
}


void printResult() {
    cout << " queens: " ;
    for (int i=0; i<pSize; i++) {
        cout << queens[i] << " ";
    }
    cout << endl << endl;
    for (int r=0; r<pSize; r++) {
        for (int c = 0; c<pSize; c++) {
            if (queens[r]==c+1)
                cout << " Q" ;
            else if ((r+c)%2==0)
                cout << "  ";
            else
                cout << " -";
        }
        cout << endl;
    }
}

int main() {
    // clear queens array
    for (int i = 0; i<pSize; i++)
        queens[i]=0;
    
    workingQueen = 0;
    queens[workingQueen]=1;
    
    while (workingQueen<pSize) {
        //cout << " working on " << workingQueen << " with " ;
        //cout << ":"<<queens[0] << queens[1] << queens[2] << queens[3] << endl;
        if (queens[workingQueen]<=pSize
            && checkDiag(workingQueen)
            && checkCols(workingQueen)) {          // OK so far - start next
            workingQueen++;
            if (workingQueen<pSize)
                queens[workingQueen]=1;
        } else {               // failed placement - try next value if possie
            if (queens[workingQueen]<pSize) {          // advance
                queens[workingQueen]++;
            } else {                                   // backtrack
                if (workingQueen<1) exit(1);           // no solution if we backtrack past the beginning!?!
                queens[workingQueen]=0;
                workingQueen--;
                queens[workingQueen]++;
            }
        }
    }
    
    printResult();
    cout << endl << "DONE" << endl;
    return 0;
}

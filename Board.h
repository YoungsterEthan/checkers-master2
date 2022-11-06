#include <iostream>
using namespace std;

#ifndef BOARD_H
#define BOARD_H

#include <list>
#include "Checker.h"
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>
// #include "move.h"

class Board{
    private:
    int ROWS;
    Checker ***checkers; //Handles the 2D array dynamically

    public:
        
        Board(int n);//constructor
        Board(const Board & b);//copy constructor
        ~Board();//destructor
        void Display();
        Checker *getchecker(int x, int y);
        list<Checker*> listCheckers;
        queue<Checker*> getInstances(char color);    // returns vectors of instances of color
        bool isAllowed(Checker *checker);
        list<Checker*> allowedMoves(queue<Checker*> instances);
        void swap(Checker *check1, Checker *check2);
        int getRows();

};


#endif /* BOARD_H */

//checkers v7
#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Board.h"
#include "Checker.h"
#include "Game.h"

using namespace std;
const int SIZE = 8;

bool compareCaptured(Checker *check1, Checker *check2){
    return (check1->numCaptured > check2->numCaptured);
}


int main(){
    //initialize game object
    Game game;
    //play game
    game.Play();
    cout << "Game Stats" << endl;
    //get a list of the checker pieces with their original colors and positions to see their stats
    list<Checker*> statsCheckers = game.getBoard()->listCheckers;
    //sort based off number of pieces captured
    statsCheckers.sort(compareCaptured);
    list<Checker*>::iterator it = statsCheckers.begin();

    //print piece with original color and position with number captured
    auto print = [](const Checker *n) { if(n->cOrig != '0') cout << n->cOrig << "-" << n->pOrig << ": " << n->numCaptured << endl;};
    cout << "For each" << endl;
    for_each(statsCheckers.begin(), statsCheckers.end(), print);

    cout << "History of moves" << endl;
    for(auto it: statsCheckers){
        cout << it->pOrig << " history" << endl;
        if(it->descriptions.empty())
            continue;
        while(!it->descriptions.empty()){
            cout << it->descriptions.top() << endl;
            it->descriptions.pop();

        }
    }
}



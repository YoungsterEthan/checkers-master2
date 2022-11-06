#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

#ifndef CHECKER_H
#define CHECKER_H

struct coord{
    int x;
    int y;

    friend ostream& operator<<(ostream& os, const coord& pos){
        os << '(' << pos.x << ',' << pos.y << ')';
        return os;
    }

    friend bool operator==(const coord& lhs, const coord& rhs){
        if(lhs.x == rhs.x && lhs.y == rhs.y)
            return true;
        else
            return false;
    }

    bool operator<(const coord& rhs) const{
        if(x == rhs.x){
            return y < rhs.y;
        } else{
            return x < rhs.x;
        }
    }
};

class Checker{
    private:
        coord pos;
        char color;
        bool isKinged;

        
        // int direction;
        

    public:
        int direction;
        bool canCapture;
        set<coord> moves;
        stack<string> descriptions;
        int numMoves;
        int numCaptured;
        char cOrig;
        coord pOrig;
        // static int totalMoves;
        Checker(int x, int y, char col);
        // Checker(int, int, char);
        friend ostream& operator<<(ostream& os, const Checker& check);
        coord getPosition();
        void changePosition(coord);
        char getColor();
        bool getisKinged();
        void addMove(coord move);
        void change(char col);
        void clear();
        coord getOpos();
        char getOc();

};


#endif /* CHECKER_H */

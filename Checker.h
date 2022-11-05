#include <iostream>
#include <vector>
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
        vector<coord> moves;
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

};


#endif /* CHECKER_H */

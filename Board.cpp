#include "Board.h"
#include <iostream>
#include <string>
using namespace std;

Board::Board(int n){
    ROWS = n;
    int COLS = n;
    checkers = new Checker**[ROWS];  

    for(int i = 0; i < ROWS; i++){
        //Declare a memory block of size COLS (n since a checker board is square)
        checkers[i] = new Checker*[COLS];
    }

    for(int i = 0;i < ROWS; i++){   // follows the rows
        for(int j = 0; j < ROWS; j++){  //follows the columns
            if(i < 3){                  // creating the black checkers
            if(i%2 == 0){
                if(j% 2 == 0){
                    checkers[i][j] = new Checker(i,j,'B');
                } else{
                    checkers[i][j] = new Checker(i,j, '0');
                }
            } else{
                if(j % 2 == 1){
                    checkers[i][j] = new Checker(i,j,'B');
                } else{
                    checkers[i][j] = new Checker(i,j,'0');
                }
            }
            } else if(i > 4){
           if(i%2 == 0){
                if(j% 2 == 0){
                    checkers[i][j] = new Checker(i,j,'R');
                } else{
                    checkers[i][j] = new Checker(i,j,'0');
                }
            } else{
                if(j % 2 == 1){
                    checkers[i][j] = new Checker(i,j,'R');
                } else{
                   checkers[i][j] = new Checker(i,j, '0');
                }
            }
            } else{
                checkers[i][j] = new Checker(i,j, '0');
            }

                listCheckers.push_back(checkers[i][j]);
            }
            
        }

        
}

Board::Board(const Board &b){
    ROWS = b.ROWS;
    int COLS = ROWS;
    checkers = new Checker**[ROWS];

    for(int i = 0; i < ROWS; i++){
        //Declare a memory block of size COLS (n since a checker board is square)
        checkers[i] = new Checker*[COLS];
    }

    for(int i = 0;i < ROWS; i++){   // follows the rows
        for(int j = 0; j < ROWS; j++){  //follows the columns
            checkers[i][j] = b.checkers[i][j];
        }
    }

}

Board::~Board(){
      for(int i=0;i<ROWS;i++)    //To delete the inner arrays
      delete [] checkers[i];   

      delete [] checkers;              //To delete the outer array
                              //which contained the pointers
                              //of all the inner arrays
}

void Board::Display(){
 cout << "==================================================================================\n\n\n\n";
    cout << "       0         1         2         3         4         5         6         7     \n";
    cout << "  _________________________________________________________________________________\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "0 |    " << *checkers[0][0] << "    |    " << *checkers[0][1] << "    |    " << *checkers[0][2] << "    |    "  << *checkers[0][3] << "    |    " << *checkers[0][4] << "    |    " << *checkers[0][5] << "    |    " << *checkers[0][6] << "    |    " << *checkers[0][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "1 |    " << *checkers[1][0] << "    |    " << *checkers[1][1] << "    |    " << *checkers[1][2] << "    |    "  << *checkers[1][3] << "    |    " << *checkers[1][4] << "    |    " << *checkers[1][5] << "    |    " << *checkers[1][6] << "    |    " << *checkers[1][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "2 |    " << *checkers[2][0] << "    |    " << *checkers[2][1] << "    |    " << *checkers[2][2] << "    |    "  << *checkers[2][3] << "    |    " << *checkers[2][4] << "    |    " << *checkers[2][5] << "    |    " << *checkers[2][6] << "    |    " << *checkers[2][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "3 |    " << *checkers[3][0] << "    |    " << *checkers[3][1] << "    |    " << *checkers[3][2] << "    |    "  << *checkers[3][3] << "    |    " << *checkers[3][4] << "    |    " << *checkers[3][5] << "    |    " << *checkers[3][6] << "    |    " << *checkers[3][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "4 |    " << *checkers[4][0] << "    |    " << *checkers[4][1] << "    |    " << *checkers[4][2] << "    |    "  << *checkers[4][3] << "    |    " << *checkers[4][4] << "    |    " << *checkers[4][5] << "    |    " << *checkers[4][6] << "    |    " << *checkers[4][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "5 |    " << *checkers[5][0] << "    |    " << *checkers[5][1] << "    |    " << *checkers[5][2] << "    |    "  << *checkers[5][3] << "    |    " << *checkers[5][4] << "    |    " << *checkers[5][5] << "    |    " << *checkers[5][6] << "    |    " << *checkers[5][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "6 |    " << *checkers[6][0] << "    |    " << *checkers[6][1] << "    |    " << *checkers[6][2] << "    |    "  << *checkers[6][3] << "    |    " << *checkers[6][4] << "    |    " << *checkers[6][5] << "    |    " << *checkers[6][6] << "    |    " << *checkers[6][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "7 |    " << *checkers[7][0] << "    |    " << *checkers[7][1] << "    |    " << *checkers[7][2] << "    |    "  << *checkers[7][3] << "    |    " << *checkers[7][4] << "    |    " << *checkers[7][5] << "    |    " << *checkers[7][6] << "    |    " << *checkers[7][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
}



Checker *Board::getchecker(int x, int y){
    if(x < 8 && x >=0 && y < 8 && y >=0)
        return checkers[x][y];
    else
        return NULL;
}

int Board::getRows(){
    return ROWS;
}


void Board::swap(Checker *check1, Checker *check2){
    // cout << "Check 1 old position: " << check1->getPosition() << endl;
    // cout << "Check 2 old position: " << check2->getPosition() << endl;

    string desc = "(" + to_string(check1->getPosition().x) + "," + to_string(check1->getPosition().y) + ") to (" + to_string(check2->getPosition().x) + "," + to_string(check2->getPosition().y) + ")";
    check1->descriptions.push(desc);


    checkers[check1->getPosition().x][check1->getPosition().y] = check2;
    checkers[check2->getPosition().x][check2->getPosition().y] = check1;
    

    coord temp = check1->getPosition();
    check1->changePosition(check2->getPosition());
    check2->changePosition(temp);
    check1->numMoves++;
    // check1->totalMoves++;

    // cout << "Check 1 new position: " << check1->getPosition() << endl;
    // cout << "Check 2 new position: " << check2->getPosition() << endl;


}

 queue<Checker*> Board::getInstances(char color){   // returns vectors of instances of color

    queue<Checker*> instances;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(checkers[i][j]->getColor() == color){
                instances.push(checkers[i][j]);
            }
        
    }
    }

    return instances;
    
 }

bool Board::isAllowed(Checker *checker){
    //Creating pointers to checker pieces that are in the reach of the checker piece we want to test
    Checker *checkerP = getchecker(checker->getPosition().x + checker->direction, checker->getPosition().y + 1);
    Checker *checkerM = getchecker(checker->getPosition().x + checker->direction, checker->getPosition().y -1);
   
//    cout << checker->getPosition() << endl;
//    cout << "Left: "; 
//    if(checkerM){cout << *checkerM<< endl;}
//    cout << "Right: ";
//    if(checkerP){cout << *checkerP<< endl;}

    bool canMove = false;

    // if(checkerP){
    //     //If the pointer points to a zero, then there is an open spaxe
    //     if(checkerP->getColor() == '0'){
    //         checker->addMove(checkerP->getPosition());
    //         canMove = true;
    //         //If the pointer points to something that is not a zero, and it is the opposite color
    //     }else if(checkerP->getColor() != checker->getColor() && checkerP->getColor() != '0' ){
    //         // We need to check if the space after that is open
    //         Checker *checkp2 = getchecker(checkerP->getPosition().x + checker->direction,checkerP->getPosition().y + 1);
    //         // if checkerp2 is in bounds
    //         if(checkp2){
    //             //if checkerp2 is open
    //         if(checkp2->getColor() == '0'){
    //             checker->canCapture = true;
    //             checker->moves.clear();
    //             checker->addMove(checkerP->getPosition());
    //             canMove = true;
    //         }
    //         }
    // }
    // }

    if(checkerP){
        //If the pointer points to a zero, then there is an open spaxe
        if(checkerP->getColor() != checker->getColor() && checkerP->getColor() != '0' ){
            // We need to check if the space after that is open
            Checker *checkp2 = getchecker(checkerP->getPosition().x + checker->direction,checkerP->getPosition().y + 1);
            // if checkerp2 is in bounds
            if(checkp2){
                //if checkerp2 is open
                if(checkp2->getColor() == '0'){
                    checker->canCapture = true;
                    checker->addMove(checkerP->getPosition());
                    canMove = true;
                }
            }
        }

        if(!checker->canCapture){
            if(checkerP->getColor() == '0'){
                checker->addMove(checkerP->getPosition());
                canMove = true;
                //If the pointer points to something that is not a zero, and it is the opposite color
            } 
        }
    }

    if(checkerM){
        if(checkerM->getColor() != checker->getColor() && checkerM->getColor() != '0'){
            Checker *checkm2 = getchecker(checkerM->getPosition().x + checker->direction, checkerM->getPosition().y -1);
            if(checkm2){
                if(checkm2->getColor() == '0'){
                    if(!checker->canCapture)
                        checker->moves.clear();
                    checker->canCapture = true;
                    checker->addMove(checkerM->getPosition());
                    canMove = true;
                }
            }

        }

        if(!checker->canCapture){
            if(checkerM->getColor() == '0'){
                    checker->addMove(checkerM->getPosition());
                    canMove = true;
            }
        }
    }
    



    if(checker->getisKinged()){
        checkerP = getchecker(checker->getPosition().x - checker->direction, checker->getPosition().y + 1);
        checkerM = getchecker(checker->getPosition().x - checker->direction, checker->getPosition().y -1);


    if(checkerP){
        //If the pointer points to a zero, then there is an open spaxe
        if(checkerP->getColor() != checker->getColor() && checkerP->getColor() != '0' ){
            // We need to check if the space after that is open
            Checker *checkp2 = getchecker(checkerP->getPosition().x - checker->direction,checkerP->getPosition().y + 1);
            // if checkerp2 is in bounds
            if(checkp2){
                //if checkerp2 is open
                if(checkp2->getColor() == '0'){
                    if(!checker->canCapture)
                        checker->moves.clear();
                    checker->canCapture = true;
                    checker->addMove(checkerP->getPosition());
                    canMove = true;
                }
            }
        }

        if(!checker->canCapture){
            if(checkerP->getColor() == '0'){
                checker->addMove(checkerP->getPosition());
                canMove = true;
                //If the pointer points to something that is not a zero, and it is the opposite color
            } 
        }
    }

    if(checkerM){

        if(checkerM->getColor() != checker->getColor() && checkerM->getColor() != '0'){
            Checker *checkm2 = getchecker(checkerM->getPosition().x - checker->direction, checkerM->getPosition().y -1);
            if(checkm2){
                if(checkm2->getColor() == '0'){
                    if(!checker->canCapture)
                        checker->moves.clear();
                    checker->canCapture = true;
                    checker->addMove(checkerM->getPosition());
                    canMove = true;
                }
            }

        }

        if(!checker->canCapture){
            if(checkerM->getColor() == '0'){
                    checker->addMove(checkerM->getPosition());
                    canMove = true;
            }
        }


        }
        
    }
    


    return canMove;


}


list<Checker*> Board::allowedMoves(queue<Checker*> instances){
    list<Checker*> allowed;
    
    while (!instances.empty()){
        if(isAllowed(instances.front())){
            allowed.push_back(instances.front());
        }
        instances.pop();
    }

    return allowed;
}


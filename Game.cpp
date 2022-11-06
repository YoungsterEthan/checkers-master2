#include "Game.h"
#include "Board.h"

using namespace std;

Game::Game(){// constructor builds the player
    player1.color = 'R';
    player2.color = 'B';
    
    player1.allowed = board->allowedMoves(board->getInstances(player1.color));
    player2.allowed = board->allowedMoves(board->getInstances(player2.color));
    currentPlayer = &player1;
}

void Game::changeTurns(){// changes turns by switching the current player
    if(currentPlayer == &player1){
        currentPlayer = &player2;
    } else{
        currentPlayer = &player1;
    }
}

int Game::update(){// checks if there is a winner at the end of each turn
        for(auto x: player1.allowed){
            x->moves.clear();
            x->canCapture = false;
        }

        for(auto x: player2.allowed){
            x->moves.clear();
            x->canCapture = false;
        }

        player1.allowed.clear();
        player2.allowed.clear();
        
        queue<Checker*> instanceP1 = board->getInstances(player1.color);
        queue<Checker*> instanceP2 = board->getInstances(player2.color);
        cout << "Instances of player 1";
        // for(auto x: instanceP1){
        //     cout << x->getPosition() << " ";
        // }

        // cout <<  endl;

        // cout << "Instances of player 2";
        // for(auto x: instanceP2){
        //     cout << x->getPosition() << " ";
        // }
        // cout <<  endl;

        player1.allowed = board->allowedMoves(board->getInstances(player1.color));
        player2.allowed = board->allowedMoves(board->getInstances(player2.color));



    if(scoreBoard[&player1] == 12 || player2.allowed.size() == 0){
        cout << "Player 1 wins" << endl;
        return 0;
    } else if (scoreBoard[&player2] == 12 || player1.allowed.size() == 0){
        cout << "Player 2 wins" << endl;
        return 0;
    }



    return 1;
}

Checker *Game::choosePiece(list<Checker*> s){
    list<Checker*>::iterator it;

    int i = 1;
    for(auto x: s){
        cout << i << ". " << x->getPosition() << endl;
        i++;
    }

    int choice;
    do{
    cout << "Choose a piece" << endl;
    cin >> choice;
    choice = int(choice);
    }while(choice <= 0 || choice > i-1);
    it = s.begin();

    for(int i = 0; i < choice - 1; i++){
        it++;
    }


    return *it;
}

coord Game::chooseDestination(Checker* piece){
   set<coord>::iterator it = piece->moves.begin();

    int i = 1;
    for(it; it != piece->moves.end(); it++){
        cout << i << ". " << *it << endl;
        i++;
    }

    int choice;
    do{
    cout << "Choose a move" << endl;
    cin >> choice;
    }while(choice <= 0 || choice > i-1);
    coord ans = *next(piece->moves.begin(), choice);
    it = piece->moves.begin();
    for(int i = 0; i < choice-1; i++){
        it++;
    }
   

    return *it;
    
}

void Game::capture(Checker *check1, Checker *check2){
    check1->numCaptured++;
    currentPlayer->numCaptured +=1;
    cout << "Captured!" << endl;
    check2->change('0');
    int calcx = check2->getPosition().x - check1->getPosition().x;
    int calcy = check2->getPosition().y - check1->getPosition().y;

    board->swap(check1, board->getchecker(check2->getPosition().x + calcx, check2->getPosition().y + calcy));
    scoreBoard[currentPlayer]++;

}


void Game::Play(){
    bool canCapt = false;
    list<Checker*> attackers;

    do{
        board->Display();
        cout << "Player 1 #captured: " << scoreBoard[&player1] << endl;
        cout << "Player 2 #captured: " << scoreBoard[&player2] << endl;
        cout << currentPlayer->color << "'s turn" << endl;

        for(auto x: currentPlayer->allowed){
            if(x->canCapture){
                canCapt = true;
                attackers.push_back(x);
            }
        }

        Checker* piece;
        coord move;
        if(canCapt){
            piece = choosePiece(attackers);
            cout << "You chose: " << piece->getPosition() << endl;
            move = chooseDestination(piece);
            capture(piece, board->getchecker(move.x, move.y));
        }else {
            piece = choosePiece(currentPlayer->allowed);
            cout << "You chose: " << piece->getPosition() << endl;
            move = chooseDestination(piece);
            board->swap(piece, board->getchecker(move.x, move.y));
        }

        


        attackers.clear();
        canCapt = false;

        changeTurns();

    }while(update() != 0);
}

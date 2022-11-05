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
        
        vector<Checker*> instanceP1 = board->getInstances(player1.color);
        vector<Checker*> instanceP2 = board->getInstances(player2.color);
        cout << "Instances of player 1";
        for(auto x: instanceP1){
            cout << x->getPosition() << " ";
        }

        cout <<  endl;

        cout << "Instances of player 2";
        for(auto x: instanceP2){
            cout << x->getPosition() << " ";
        }
        cout <<  endl;

        player1.allowed = board->allowedMoves(board->getInstances(player1.color));
        player2.allowed = board->allowedMoves(board->getInstances(player2.color));



    if(player1.numCaptured == 12 || player2.allowed.size() == 0){
        cout << "Player 1 wins" << endl;
        return 0;
    } else if (player2.numCaptured == 12 || player1.allowed.size() == 0){
        cout << "Player 2 wins" << endl;
        return 0;
    }



    return 1;
}

Checker *Game::choosePiece(vector<Checker*> s){
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


    return s[choice - 1];
}

coord Game::chooseDestination(Checker* piece){
    int i = 1;
    for(auto x: piece->moves){
        cout << i << ". " << x << endl;
        i++;
    }

    int choice;
    do{
    cout << "Choose a move" << endl;
    cin >> choice;
    }while(choice <= 0 || choice > i-1);

    return piece->moves[choice - 1];
    
}

void Game::capture(Checker *check1, Checker *check2){
    currentPlayer->numCaptured +=1;
    cout << "Captured!" << endl;
    check2->change('0');
    int calcx = check2->getPosition().x - check1->getPosition().x;
    int calcy = check2->getPosition().y - check1->getPosition().y;

    board->swap(check1, board->getchecker(check2->getPosition().x + calcx, check2->getPosition().y + calcy));

}


void Game::Play(){
    bool canCapt = false;
    vector<Checker*> attackers;

    do{
        board->Display();
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

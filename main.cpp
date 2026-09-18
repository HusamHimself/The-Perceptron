#include <iostream>

//Thanks to welsh labs for writig a fascinating book.

void displayBoard(bool board[4][4]);


int main(){
    double learning_rate = 0;
    bool switches[4][4] =  {{false, false, false, false},
                            {false, false, false, false},
                            {false, false, false, false},
                            {false, false, false, false}};

    displayBoard(switches);

    
}

void displayBoard(bool board[4][4]){

    for(int row = 0; row < 4; row++){
        for(int column = 0; column < 4; column++){
            if(board[row][column] == false){
                std::cout <<"0 ";
                continue;
            }
            std::cout <<"1 ";
        }
        std::cout << '\n';
    }

}
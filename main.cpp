#include <iostream>

//Thanks to welsh labs for writig a fascinating book.

void displayBoard(bool board[4][4]);
double calculatedSum(bool switches[4][4], double weights[4][4]);
double learnFrom(bool switches[4][4], double weights[4][4], double learning_rate);
double closeAllSwitches(double switches[4][4]);

int main(){
    double learning_rate = 0.01;
    bool switches[4][4] =  {{false, false, false, false},
                            {false, false, false, false},
                            {false, false, false, false},
                            {false, false, false, false}};
    double weights[4][4] = {{0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}};
    
    displayBoard(switches);

}

double closeAllSwitches(double switches[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            switches[i][j] = false;
        }
    }
}

double learnFrom(bool switches[4][4], double weights[4][4], double learning_rate){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(switches[i][j] == true){
                weights[i][j] += learning_rate;
                continue;
            }
            weights[i][j] -= learning_rate;
        }
    }
    return weights[4][4];
}

double calculatedSum(bool switches[4][4], double weights[4][4]){
    double the_sum = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(switches[i][j] == true){
                the_sum += switches[i][j];
            }
        }
    }
    return the_sum;
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
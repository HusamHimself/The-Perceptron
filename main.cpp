#include <iostream>

//Thanks to welsh labs for writig a fascinating book.

void displayBoard(bool board[4][4]);
double calculatedSum(bool switches[4][4], double weights[4][4]);
void adjustWeights(bool switches[4][4], double weights[4][4], double learning_rate, bool positive);
void closeAllSwitches(double switches[4][4]);
void makeFirstT(bool switches[4][4]);
void makeSecondT(bool switches[4][4]);
void makeFirstJ(bool switches[4][4]);
void makeSecondJ(bool switches[4][4]);

int main(){
    double learning_rate = 0.1;
    bool switches[4][4] =  {{false, false, false, false},
                            {false, false, false, false},
                            {false, false, false, false},
                            {false, false, false, false}};
    double weights[4][4] = {{0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}};

    makeSecondJ(switches);
    displayBoard(switches);
    adjustWeights(switches, weights, learning_rate, true);
    std::cout <<calculatedSum(switches, weights);
}

void makeFirstJ(bool switches[4][4]){
    switches[0][3] = true;
    switches[1][3] = true;
    switches[2][3] = true;
    switches[3][3] = true;
    switches[3][2] = true;
    switches[3][1] = true;
    switches[2][1] = true;
}
void makeSecondJ(bool switches[4][4]){
    switches[0][2] = true;
    switches[1][2] = true;
    switches[2][2] = true;
    switches[3][2] = true;
    switches[3][1] = true;
    switches[3][0] = true;
    switches[2][0] = true;
}

void makeSecondT(bool switches[4][4]){
    switches[0][0] = true;
    switches[0][2] = true;
    switches[0][1] = true;
    switches[1][1] = true;
    switches[2][1] = true;
    switches[3][1] = true;
}

void makeFirstT(bool switches[4][4]){
    switches[0][3] = true;
    switches[0][2] = true;
    switches[0][1] = true;
    switches[1][2] = true;
    switches[2][2] = true;
    switches[3][2] = true;
}

void closeAllSwitches(double switches[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            switches[i][j] = false;
        }
    }
}

void adjustWeights(bool switches[4][4], double weights[4][4], double learning_rate, bool positive){
    if(positive){
        for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(switches[i][j] == true){
                weights[i][j] += learning_rate;
                continue;
            }
            weights[i][j] -= learning_rate;
            }
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(switches[i][j] == true){
                weights[i][j] -= learning_rate;
                continue;
            }
            weights[i][j] += learning_rate;
        }
    }
}

double calculatedSum(bool switches[4][4], double weights[4][4]){
    double the_sum = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(switches[i][j] == true){
                the_sum += weights[i][j];
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
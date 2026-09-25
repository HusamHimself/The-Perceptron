#include <iostream>

void displaySwitches(bool switches[4][4]);
double calculateOutput(bool switches[4][4], double weights[4][4]);
void adjustWeights(bool switches[4][4], double weights[4][4], double learning_rate, bool learning_positive);
void closeAllSwitches(bool switches[4][4]);
void makeFirstT(bool switches[4][4]);
void makeSecondT(bool switches[4][4]);
void makeFirstJ(bool switches[4][4]);
void makeSecondJ(bool switches[4][4]);
void pseudoClearTerminal();
void presenceMechanism();
void resetWeightsAndSwitches(double weights[4][4], bool switches[4][4]);


namespace Perceptron{
    bool learn_positive = true;
    bool learn_negative = false;
}

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
    char choice_layer_one = ' ';
    int errors = 0;

    makeFirstT(switches);
    adjustWeights(switches, weights, learning_rate, Perceptron::learn_positive);
    closeAllSwitches(switches);
    makeSecondT(switches);
    adjustWeights(switches, weights, learning_rate, Perceptron::learn_positive);
    closeAllSwitches(switches);
    makeFirstJ(switches);
    adjustWeights(switches, weights, learning_rate, Perceptron::learn_negative);
    closeAllSwitches(switches);
    makeSecondJ(switches);
    adjustWeights(switches, weights, learning_rate, Perceptron::learn_negative);
    closeAllSwitches(switches);

    while(true){
        do{
            if(errors > 0){
                std::cout <<"Wrong Choice Last Time Pal\n";
            }
            std::cout <<"Choices: \n";
            std::cout <<"1 = See The Switches + The Output\n";
            std::cout <<"2 = Change Switches\n";
            std::cout <<"3 = Learn Positively\n";
            std::cout <<"4 = Learn Negatively\n";
            std::cout <<"5 = Reset Switches And Weights.\n";
            std::cout <<"6 = Close The Program.\n";
            std::cout <<"Choice : ";
            std::cin >> choice_layer_one;
            errors++;
        }while(choice_layer_one != '1' && choice_layer_one != '2' && choice_layer_one != '3' && choice_layer_one != '4' && choice_layer_one != '5');
        errors = 0;
        pseudoClearTerminal();

        switch(choice_layer_one){
            case '1':
            {
                
                displaySwitches(switches);
                std::cout <<"Board Output = "<< calculateOutput(switches, weights)<<"\n";
            }
            break;

            case '2':
            {
                char temp_choice = ' ';
                do{
                    std::cout <<"1 = Switch On The First T\n";
                    std::cout <<"2 = Switch On The Second T\n";
                    std::cout <<"3 = Switch On the First J\n";
                    std::cout <<"4 = Switch On the Second J\n";
                    std::cout <<"5 = Switch Off All Switches\n";
                    std::cout <<": ";
                    std::cin >>temp_choice;
                }while(temp_choice != '1' && temp_choice != '2' && temp_choice != '3' && temp_choice!= '4' && temp_choice != '5');

                switch(temp_choice){
                    case '1':
                        makeFirstT(switches);
                        break;
                    case '2':
                        makeSecondT(switches);
                        break;
                    case '3':
                        makeFirstJ(switches);
                        break;
                    case '4':
                        makeSecondJ(switches);
                        break;
                    case '5':
                        closeAllSwitches(switches);
                        break;
                }
                pseudoClearTerminal();
                continue;
            }
            break;

            case '3':
                adjustWeights(switches, weights, learning_rate, Perceptron::learn_positive);
                std::cout <<"Weights Adjusted Positively.";
                break;
            
            case '4':
                adjustWeights(switches, weights, learning_rate, Perceptron::learn_negative);
                std::cout <<"Weights Adjusted Negatively.";
                break;
            
            case '5':
                resetWeightsAndSwitches(weights, switches);
                std::cout <<"Resetted all weights and switches.";
                break;
            
            case '6':
            {
                char answer = ' ';
                std::cout <<"\nAre you sure you wanna close the program?\n";
                std::cout <<"enter 'n' to cancel or anything else to close the program";
                std::cin >>answer;
                if(answer == 'n'){
                    return 0;
                }
                continue;
            }
                
        };
        choice_layer_one = ' ';
        presenceMechanism();
    }

}

void resetWeightsAndSwitches(double weights[4][4], bool switches[4][4]){
    closeAllSwitches(switches);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            weights[i][j] = 0;
        }
    }
}

void presenceMechanism(){
    std::string useless = " ";
    std::cout <<"\n\nEnter Anything To Move on\n: ";
    std::cin >>useless;
    pseudoClearTerminal();
}

void pseudoClearTerminal(){
    for(int i = 0; i < 50; i++){
        std::cout <<'\n';
    }
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

void closeAllSwitches(bool switches[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            switches[i][j] = false;
        }
    }
}

void adjustWeights(bool switches[4][4], double weights[4][4], double learning_rate, bool learning_positive){
    if(learning_positive){
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

double calculateOutput(bool switches[4][4], double weights[4][4]){
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

void displaySwitches(bool switches[4][4]){

    for(int row = 0; row < 4; row++){
        for(int column = 0; column < 4; column++){
            if(switches[row][column] == false){
                std::cout <<"0 ";
                continue;
            }
            std::cout <<"1 ";
        }
        std::cout << '\n';
    }

}

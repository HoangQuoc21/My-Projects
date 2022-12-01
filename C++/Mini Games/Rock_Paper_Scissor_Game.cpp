#include <iostream>
#include <cstdlib>
using namespace std;

string name, choice;
int score = 0;
char player, computer;
float tries = 0, wins = 0, loses = 0, ties = 0;

int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

char getUserChoice(){
    char player;
    cout << "Type \"r\" for rock.\n";
    cout << "Type \"p\" for paper.\n";
    cout << "Type \"s\" for scissors.\n";
    cout << "----------------------------\n";
    cout << "Your selection: ";
    cin >> player;
    while(player != 'r' && player != 'p' && player != 's'){
        cout << "Invalid selection. Reselect: ";
        cin >> player;
    }
    return player;
}

char getComputerChoice(){
    srand(time(0));
    int num = rand() % 3 + 1;
    //int num = GetRandom(1,3);
    switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
}

void showChoice(char choice){
    switch(choice){
        case 'r':   
            cout << "Rock.\n";
            break;
        case 'p':   
            cout << "Paper.\n";
            break;
        case 's': 
            cout << "Scissors.\n";
            break;
    }
}

void chooseWinner (char player, char computer){
    cout << "==>";
    switch(player){
        case 'r':
            if (computer == 'r'){
                cout << "It's a tie!\n";
                ties++;
            }   
            else if (computer == 'p'){
                cout << "You lose!\n";
                score--;
                loses++;
            }
            else{
                cout << "You win!\n";
                score++;
                wins++;
            }
            break;
        case 'p':
            if (computer == 'r'){
                cout << "You win!\n";
                score++;
                wins++;
            }
            else if (computer == 'p'){
                cout << "It's a tie!\n";
                ties++;
            }
            else{
                cout << "You lose!\n";
                score--;
                loses++;
            } 
            break;
        case 's':
            if (computer == 'r'){
                cout << "You lose!\n";
                score--;
                loses++;
            } 
            else if (computer == 'p'){
                cout << "You win!\n";
                score++;
                wins++;
            }
            else{
                cout << "It's a tie!\n";
                ties++;
            } 
            break;
    }
}

void guide(){
    cout << "============================================================================================================================\n";
    cout << "=                                                              GUIDE                                                       =\n";
    cout << "============================================================================================================================\n";
    cout << "Rock-Paper-Scissors Game is a very simple game. There are only some rules:\n";
    cout << "1. You wil have to choose one in three options: Rock; Paper; Scissors.\n";
    cout << "2. Rock will win against scissors; Paper will win against rock; Scissors will win against paper.\n";
    cout << "3. After you choose your option, Computer will make their choice.\n";
    cout << "4. If you win against computer you wil get +1 score and if you lose, you wil get -1 score.\n   You can see your total play turns and some other statistics in the third option of Menu.\n";
     cout << "================================================GOOD LUCK, YOU WILL NEED IT!================================================\n";
}

void printTitle(){
    cout << "=============================================\n";
    cout << "=           Rock-Paper-Scissors Game        =\n";
    cout << "=============================================\n";
}

void playGame(){
    tries++;

    printTitle();
    player = getUserChoice();
    cout << "-Player's choice is: ";
    showChoice(player);

    computer = getComputerChoice();
    cout << "-Computer's choice is: ";
    showChoice(computer);
    cout << "----------------------------\n";
    chooseWinner(player, computer);
    cout << "*Your score is: " << score << endl;
}

void Comment (float win_rate, float losing_rate, float tie_rate){
    if(win_rate > losing_rate)
        cout << "You are quite lucky!.\n";
    else if (losing_rate > win_rate)
        cout << "You are quite unlucky!.\n";
    else
        cout << "You are neither lucky nor unlucky!\n";
}

void Statistics(){
    cout << "===========================================\n";
    cout << "=                 STATISTICS              =\n";
    cout << "===========================================\n";
    if (tries == 0)
        cout << "You have never play.\n";
    else{
        float win_rate,losing_rate,tie_rate;
        win_rate = (wins/tries)*100;
        losing_rate = (loses/tries)*100;
        tie_rate = (ties/tries)*100;
        cout << "Player: " << name << endl;
        cout << "Total score: " << score << endl;
        cout << "----------------------------\n";
        cout << "-Number of tries: " << tries << endl;
        cout << "-Number of wins: " << wins << endl;
        cout << "-Number of losses: " << loses << endl;
        cout << "-Number of ties: " << ties << endl;
        cout << "----------------------------\n";
        cout << "-Win rate: " << win_rate << "%\n";
        cout << "-Losing rate: " << losing_rate << "%\n";;
        cout << "-Tie rate: " << tie_rate << "%\n";
        Comment(win_rate, losing_rate, tie_rate);
    }
}

int main(){
    system("cls");

    printTitle();
    cout << "Firstly, please input your name: ";
    cin >> name;
    system("cls");

    while (choice != "0"){
        printTitle();
        cout << "Welcome player: " << name << " to the game.\n";
        cout << "--------------------MENU-------------------\n";
        cout << "1. How to play.\n";
        cout << "2. Play the game.\n";
        cout << "3. Show your statistical numbers.\n";
        cout << "0. Exit the game.\n";
        cout << "-------------------------------------------\n";
        cout << "Your selection: ";
        cin >> choice;
        cout << "-------------------------------------------\n";

        if (choice == "1"){
            system("cls");
            guide();
        }
        else if (choice == "2"){
            system("cls");
            string choice2;
            playGame();
            while (choice2 != "b"){
                cout << "============================\n";
                cout << "What do you want to do next?\n";
                cout << "a. Play again.\n";
                cout << "b. Come back to menu.\n";
                cout << "----------------------------\n";
                cout << "Your selection: ";
                cin >> choice2;
                if (choice2 == "a"){
                    system("cls");
                    playGame();
                }
                else if (choice2 == "b"){
                    break;
                }
                else{
                    cout << "Invalid selection.\n";
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (choice == "3"){
            system("cls");
            Statistics();
        }
        else if (choice == "0"){
            
            cout << "THANK YOU PLAYER "<< name << " FOR PLAYING!\n";
            exit(0);
        }
        else
            cout << "Invalid selection.\n";

        system("pause");
        system("cls");
    }

    return 0;
}
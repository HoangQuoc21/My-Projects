#include <iostream>

using namespace std;

void drawBoard(char *spaces){
    system("cls");
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] <<"  |  " << spaces[1] <<"  |  " << spaces[2] <<"   " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] <<"  |  " << spaces[4] <<"  |  " << spaces[5] <<"   " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] <<"  |  " << spaces[7] <<"  |  " << spaces[8] <<"   " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

void playerMove (char *spaces, char player){
    int number;
    while (!number > 0 || !number < 8){
        cout << "Enter 1 spot to place a marker (1-9): ";
        cin >> number;
        number--;
        if (spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    }
}

void computerMove (char *spaces, char computer){
    int number;
    srand(time(0));
    while(true){
        number = rand()%9;
        if (spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer){
    // Kiểm tra hàng ngang
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1] && spaces[1] == spaces[2]) ){
        spaces[0] == player? cout << "YOU WIN!\n" : cout << "COMPUTER WIN!\n";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4] && spaces[4] == spaces[5]) ){
        spaces[3] == player? cout << "YOU WIN!\n" : cout << "COMPUTER WIN!\n";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7] && spaces[7] == spaces[8]) ){
        spaces[6] == player? cout << "YOU WIN!\n" : cout << "COMPUTER WIN!\n";
    }

    //Kiểm tra hàng dọc
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3] && spaces[3] == spaces[6]) ){
        spaces[0] == player? cout << "YOU WIN!\n" : cout << "COMPUTER WIN!\n";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4] && spaces[4] == spaces[7]) ){
        spaces[1] == player? cout << "YOU WIN!\n" : cout << "COMPUTER WIN!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5] && spaces[5] == spaces[8]) ){
        spaces[2] == player? cout << "YOU WIN!\n" : cout << "COMPUTER WIN!\n";
    }

    //Kiểm Tra Hàng Chéo
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4] && spaces[4] == spaces[8]) ){
        spaces[0] == player? cout << "YOU WIN!\n" : cout << "COMPUTER WIN!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4] && spaces[4] == spaces[6]) ){
        spaces[2] == player? cout << "YOU WIN!\n" : cout << "COMPUTER WIN!\n";
    }
    else{
        return false;
    }
        
    return true;
}

bool checkTie(char *spaces, char player, char computer){
    for (int i=0; i < 9;i++){
        if (spaces[i] == ' '){
            return false;
        }
    }
    cout << "IT'S A TIE.\n";
    return true;
}

int main(){
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);
    while (running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if (checkTie(spaces, player, computer)){
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
    }
    cout << "Thanks for playing!\n";
    return 0;
}
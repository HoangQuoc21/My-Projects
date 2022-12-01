#include <iostream>
using namespace std;

int main(){
    system("cls");
    string choice;
    while (choice != "2"){
        cout << "======================NUMBER GUESSING GAME======================\n";
        cout << "1. Play the game.\n";
        cout << "2. Exit the game.\n";
        cout << "================================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "----------------------------------------------------------------\n";
        if (choice == "1"){
             int num;
            int guess;
            int tries = 0;
            num = (rand() % 100) + 1;
            while (guess != num){
                cout << "Enter a guess between (1-100): ";
                cin >> guess;
                tries++;
                if (guess > num)
                    cout << "Too high!\n";
                else if (guess < num)
                    cout << "Too low!\n";
                else 
                    cout << "CORRECT! Number of tries: " << tries << endl;
            }
        }
        else if (choice == "2"){
            cout << "Thank you for playing!\n";
            exit(0);
        }
        else
            cout << "Invalid choice!\n";
        system("pause");
        system("cls");
    }
}
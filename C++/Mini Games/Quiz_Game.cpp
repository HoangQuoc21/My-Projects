#include <iostream>
using namespace std;

int main(){
    string questions[] = {"1. What year was C++ created?",
                          "2. Who invented C++?",
                          "3. What is the predecessor of C++?",
                          "4. Is the Earth flat?"};

    string options[][4] = {{"A. 1969","B. 1975","C. 1985","D. 1989"},
                          {"A. Guido van Rossum","B. Bjarne Stroustrup", "C. John Cena", "D. Dwayne Johnson" },
                          {"A. C", "B. C++","C. C--", "D. B++"},
                          {"A. Yes","B. No","C. Sometimes","D. What's Earth?"}};
    
    char answerKey[] = {'C', 'B', 'A','B'};

    float size = sizeof(questions) / sizeof(questions[0]);
    char guess;
    float score = 0;

    cout << "================================================================\n";
    cout << "==                   WELCOME TO QUOC'S QUIZ GAME              ==\n";
    cout << "================================================================\n"; 
    system("pause");
    system("cls");
    
    for (int i = 0; i < size;  i++){
        cout << "================================================================\n";
        cout << questions[i] << "\n";
        cout << "----------------------------------------------------------------\n";
        for (int j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++){
            cout << options[i][j] << "\n";
        }
        cout << "****************\n";
        cout << "Your option: ";
        cin >> guess;
        guess = toupper(guess);
        cout << "----------------------------------------------------------------\n";
        if (guess == answerKey[i]){
            cout << "CORRECT.\n";
            score++;
        }
        else{
            cout << "WRONG. Answer: " << answerKey[i] << endl;
        }
        system("pause");
        system("cls");
    }
    cout << "================================================================\n";
    cout << "==                             RESULTS                        ==\n";
    cout << "================================================================\n";
    cout << "CORRECT GUESSES: " << score << endl;
    cout << "THE NUMBER OF QUESTIONS: " << size << endl;
    cout << "YOUR SCORES: " << (float)(score/size)*100 <<" %.\n";

}
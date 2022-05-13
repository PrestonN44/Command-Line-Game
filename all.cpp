#include "headers/all.h"

// VALIDATE INTEGER INPUT
int validateInt(int end) {
    int choice;
    cout << "\nEnter 1-" << end << ": ";
    cin >> choice;
    while (cin.fail() || (choice < 1 || choice > end)) {
        cout << "Invalid input. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }
    return choice;
}

// VALIDATE CHARACTER INPUT
char validateChar() {
    char choice;

    cout << "\n(Y/N) ";
    cin >> choice;
    if (!cin.fail()) 
        choice = tolower(choice);

    while (cin.fail() || (choice != 'y' && choice != 'n')) {
        cout << "Invalid input. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
        if (!cin.fail()) 
            choice = tolower(choice);
    }
    return choice;
}
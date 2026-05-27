#include <iostream>
#include <string>
using namespace std;

bool login(string username, string password);
double addSale();
void makeChange();
double giveRefund(double runningTotal);

int main() {
    string username, password;
    int attempts = 0;
    bool success = false;

    while (attempts < 3 && !success) {
        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        success = login(username, password);

        if (!success) {
            attempts++;
            if (attempts < 3) {
                cout << "Login failed. You have " << 3 - attempts << " attempt(s) left." << endl;
            }
        }
    }

    if (!success) {
        cout << "You have been locked " << endl;
        return 0;
    }

    double runningTotal = 0.0;
    int choice;

    do {
        cout << endl;
        cout << "Menu" << endl;
        cout << "1. Add a sale" << endl;
        cout << "2. Make change" << endl;
        cout << "3. Issue a refund" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            runningTotal += addSale();
            cout << "Running total: $" << runningTotal << endl;
        }
        else if (choice == 2) {
            makeChange();
        }
        else if (choice == 3) {
            runningTotal = giveRefund(runningTotal);
        }
        else if (choice == 4) {
            cout << "Total sales for the day: $" << runningTotal << endl;
            cout << "Program ended." << endl;
        }
        else {
            cout << "Invalid menu choice." << endl;
        }

    } while (choice != 4);

    return 0;
}

bool login(string username, string password) {
    if (username == "user" && password == "1234") {
        return true;
    }
    else {
        return false;
    }
}

double addSale() {
    double saleAmount;
    double totalWithTax;

    cout << "Enter sale amount: ";
    cin >> saleAmount;

    totalWithTax = saleAmount + (saleAmount * 0.065);

    cout << "Sale with tax : $" << totalWithTax << endl;

    return totalWithTax;
}

void makeChange() {
    int paid, owed;
    int change;
    int twenties, tens, fives, ones;

    cout << "Enter amount paid: ";
    cin >> paid;

    cout << "Enter amount owed: ";
    cin >> owed;

    if (paid < owed) {
        cout << "Needs to provide more money." << endl;
    }
    else if (paid == owed) {
        cout << "Don't need change." << endl;
    }
    else {
        change = paid - owed;

        twenties = change / 20;
        change = change % 20;

        tens = change / 10;
        change = change % 10;

        fives = change / 5;
        change = change % 5;

        ones = change / 1;

        cout << "Provide change as:" << endl;
        cout << "$20 bills: " << twenties << endl;
        cout << "$10 bills: " << tens << endl;
        cout << "$5 bills: " << fives << endl;
        cout << "$1 bills: " << ones << endl;
    }
}

double giveRefund(double runningTotal) {
    double refundAmount;

    cout << "Enter refund amount: ";
    cin >> refundAmount;

    if (runningTotal - refundAmount < 0) {
        cout << "Refund didn't go though. Speak to the manager." << endl;
    }
    else {
        runningTotal = runningTotal - refundAmount;
        cout << "Refund applied." << endl;
        cout << "New running total: $" << runningTotal << endl;
    }

    return runningTotal;
}
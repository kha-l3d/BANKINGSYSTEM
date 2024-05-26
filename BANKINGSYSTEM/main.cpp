

#include <iostream>
#include "BankingSystem.h"


using namespace std;

//  display the menu 
int displayMenu() {
    int choice;
    cout << "Menu:" << endl;
    cout << "1 - Create account" << endl;
    cout << "2 - Delete account" << endl;
    cout << "3 - Deposit" << endl;
    cout << "4 - Withdraw" << endl;
    cout << "5 - Check account balance" << endl;
    cout << "6- display count of accounts "<<endl;
    cout<<"0 - Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}



int main() {
    LinkedList accounts;
    int choice;
    int accountNumber;
    string ownerName;
    double amount;

    do {
        choice = displayMenu();
        switch (choice) {
        case 1:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter owner name: ";
            cin >> ownerName;
            cout << "Enter initial balance: ";
            cin >> amount;
            accounts.addAccount(new Account(accountNumber, ownerName, amount));

            break;
        case 2:
            cout << "Enter account number to delete: ";
            cin >> accountNumber;
            accounts.deleteAccount(accountNumber);
            break;
        case 3:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            {
                Account* account = accounts.findAccount(accountNumber);
                if (account) {
                    account->deposit(amount);
                }
                else {
                    cout << "Account not found!" << endl;
                }
            }
            break;
        case 4:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            {
                Account* account = accounts.findAccount(accountNumber);
                if (account) {
                    account->withdraw(amount);
                }
                else {
                    cout << "Account not found!" << endl;
                }
            }
            break;
        case 5:
            cout << "Enter account number: ";
            cin >> accountNumber;
            {
                Account* account = accounts.findAccount(accountNumber);
                if (account) {
                    account->printBalance();
                }
                else {
                    cout << "Account not found!" << endl;
                }
            }
            break;
        case 6:
            cout << "num  is ";
            cout << accounts.count();
            break;
      
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}



#include "BankingSystem.h"

// Constructor to initialize an account
Account::Account(int accNum, string name, double bal)
    : accountNumber(accNum), ownerName(name), balance(bal) {}

//  deposit an amount to the account
void Account::deposit(double amount) {
    balance += amount;
    cout << "Deposited: $" << amount << " to Account: " << accountNumber << endl;
}

//  withdraw an amount from the account
void Account::withdraw(double amount) {
    if (amount > balance) {
        cout << " Erorr : amount > balance " << endl;
        return;
    }
    balance -= amount;
    cout << "Withdrew: $" << amount << " from Account: " << accountNumber << endl;
}

//  print the current balance 
void Account::printBalance() const {
    cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
}

//linked list



//  add an account to the linked list
void LinkedList::addAccount(Account* account) {
    Node* newNode = new Node(account);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr
            ) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Account created: " << account->accountNumber << endl;
}

// delete an account from the linked list
void LinkedList::deleteAccount(int accountNumber) {
    if (head == nullptr) return;

    if (head->account->accountNumber == accountNumber) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Account deleted: " << accountNumber << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->account->accountNumber != accountNumber) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Account not found: " << accountNumber << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    cout << "Account deleted: " << accountNumber << endl;
}

// find an account 
Account* LinkedList::findAccount(int accountNumber) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->account->accountNumber == accountNumber) {
            return temp->account;
        }
        temp = temp->next;
    }
    return nullptr;
}

//  print all accounts in the linked list
void LinkedList::printAccounts() const {
    Node* temp = head;
    while (temp != nullptr) {
        temp->account->printBalance();
        temp = temp->next;
    }
    
    }
int LinkedList::count() const {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        ++count;
        temp = temp->next;
    }
    return count;

}

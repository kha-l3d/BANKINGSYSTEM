

#include <iostream>
#include <string>

using namespace std;



// Account class manage  accounts
class Account {
public:
    int accountNumber;
    string ownerName;
    double balance;
   

    Account(int accNum, string name, double bal);

    void deposit(double amount);
    void withdraw(double amount);
    void printBalance() const;
   
};

// Node struct  the linked list  accounts
struct Node {
    Account* account;
    Node* next;
    Node(Account* acc) : account(acc), next(nullptr) {}
};

// LinkedList class to manage the list of accounts
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void addAccount(Account* account);
    void deleteAccount(int accountNumber);
    Account* findAccount(int accountNumber);
    void printAccounts() const;
    int count() const;
};




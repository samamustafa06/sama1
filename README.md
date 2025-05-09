// BankSystem_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_ACCOUNTS = 100; // Maximum number of accounts

struct Account 
{
    long long id;
    string name;
    string password;
    double balance;
};

vector<Account> accounts; // Vector to store account information

// Function to save accounts to a file
void saveAccountsToFile() 
{
    ofstream file("accounts.txt");
    for (const auto& account : accounts) 
    {
        file << account.id << " " << account.name << " " << account.password << " " << account.balance << "\n";
    }
    file.close();
}

// Function to load accounts from a file
void loadAccountsFromFile() 
{
    ifstream file("accounts.txt");
    Account account;
    while (file >> account.id >> account.name >> account.password >> account.balance)
        {
        accounts.push_back(account);
        }
    file.close();
}

// Function to create a new account
void createAccount() 
{
    if (accounts.size() >= MAX_ACCOUNTS)
    {
        cout << "Cannot create more accounts. Limit reached.\n";
    }

    Account newAccount;
    cout << "Create account\n";
    cout << "Enter name: ";
    cin >> newAccount.name;
    cout << "Enter ID: ";
    cin >> newAccount.id;
    cout << "Enter password: ";
    cin >> newAccount.password;
    newAccount.balance = 0.0;

    accounts.push_back(newAccount);
    saveAccountsToFile();
    cout << "Account created successfully.\n";
}

// Function to login
int login() 
{
    long long id;
    string password;

    cout << "Enter account ID: ";
    cin >> id;
    cout << "Enter password: ";
    cin >> password;

    for (size_t i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].id == id && accounts[i].password == password) 
        {
            return i; // Return the index of the logged-in account
        }
    }

    cout << "Invalid ID or password.\n";
    return -1; // Return -1 if login fails
}

// Function to deposit money
void depositMoney()
{
    int i = login();
    if (i == -1)
        return;

    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount <= 0) 
    {
        cout << "Invalid amount. Please enter a positive value.\n";
        return;
    }

    accounts[i].balance += amount;
    saveAccountsToFile();
    cout << "Deposit successful. New balance: " << accounts[i].balance << "\n";
}

// Function to withdraw money
void withdrawMoney() 
{
    int i = login();
    if (i == -1) 
        return;

    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount <= 0) 
    {
        cout << "Invalid amount. Please enter a positive value.\n";
        return;
    }

    if (accounts[i].balance >= amount)
    {
        accounts[i].balance -= amount;
        saveAccountsToFile();
        cout << "Withdrawal successful. New balance: " << accounts[i].balance << "\n";
    }
    else
    {
        cout << "Insufficient balance.\n";
    }
}

// Function to check balance
void checkBalance()
{
    int i = login();
    if (i == -1) 
        return;

    cout << "Current balance: " << accounts[i].balance << "\n";
}

// Function to close an account
void closeAccount() 
{
    int i = login();
    if (i == -1) 
        return;

    accounts.erase(accounts.begin() + i);
    saveAccountsToFile();
    cout << "Account closed successfully.\n";
}

// Main function
int main() 
{
    loadAccountsFromFile();
    int choice;

    while (true) 
    {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Close Account\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            createAccount();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            checkBalance();
            break;
        case 5:
            closeAccount();
            break;
        case 6:
            cout << "Exiting the system.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}


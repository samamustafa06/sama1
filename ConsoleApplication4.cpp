#include <iostream>
#include <string>

using namespace std;

// Global variables to store current account information
int password1 = 0;
long long Id1 = 0;
double balance = 0.0;
string name;

// Maximum number of accounts allowed
const int MAX_ACCOUNTS = 100;

// Arrays to store information for all accounts
long long accountIds[MAX_ACCOUNTS];
int accountPasswords[MAX_ACCOUNTS];
double accountBalances[MAX_ACCOUNTS];
string accountNames[MAX_ACCOUNTS];

// Counter to keep track of the number of accounts created
int accountCount = 0;

// Function to create a new account
void createAccount() 
{
    // Check if the maximum number of accounts has been reached
    if (accountCount >= MAX_ACCOUNTS) 
    {
        cout << "Cannot create more accounts. Limit reached.\n";
        return;
    }

    // Prompt the user for account details
    cout << "Create account\n";
    cout << "Enter name: ";
    cin >> accountNames[accountCount];
    cout << "Enter ID: ";
    cin >> accountIds[accountCount];
    cout << "Enter password: ";
    cin >> accountPasswords[accountCount];

    // Set the initial balance to 0.0
    accountBalances[accountCount] = 0.0;

    // Increment the account count
    accountCount++;
    cout << "Account created successfully.\n";
}

// Function to deposit money into an account
void depositMoney() 
{
    int password2;
    long long Id2;
    double amount;

    // Prompt the user for account ID, password, and deposit amount
    cout << "Enter account ID: ";
    cin >> Id2;
    cout << "Enter password: ";
    cin >> password2;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    // Search for the account using the provided ID and password
    for (int i = 0; i < accountCount; i++) 
    {
        if (accountIds[i] == Id2 && accountPasswords[i] == password2) 
        {
            // Add the deposit amount to the current balance
            accountBalances[i] += amount;
            cout << "Deposit successful. New balance: " << accountBalances[i] << "\n";
            return;
        }
    }

    // If the account is not found or the password is incorrect
    cout << "Invalid password or ID.\n";
}

// Function to withdraw money from an account
void withdrawMoney() 
{
    long long Id2;
    double amount;

    // Prompt the user for account ID and withdrawal amount
    cout << "Enter account ID: ";
    cin >> Id2;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    // Search for the account using the provided ID
    for (int i = 0; i < accountCount; i++) 
    {
        if (accountIds[i] == Id2) {
            // Check if the account has sufficient balance
            if (accountBalances[i] >= amount) 
            {
                // Deduct the withdrawal amount from the current balance
                accountBalances[i] -= amount;
                cout << "Withdrawal successful. New balance: " << accountBalances[i] << "\n";
            }
            else {
                // If the balance is insufficient
                cout << "Insufficient balance.\n";
            }
            return;
        }
    }

    // If the account is not found
    cout << "Account not found.\n";
}

// Function to check the balance of an account
void checkBalance() 
{
    long long Id2;

    // Prompt the user for account ID
    cout << "Enter account ID: ";
    cin >> Id2;

    // Search for the account using the provided ID
    for (int i = 0; i < accountCount; i++) 
    {
        if (accountIds[i] == Id2) 
        {
            // Display the current balance
            cout << "Current balance: " << accountBalances[i] << "\n";
            return;
        }
    }

    // If the account is not found
    cout << "Account not found.\n";
}

// Function to close an account
void closeAccount() 
{
    long long Id2;

    // Prompt the user for account ID to close
    cout << "Enter account ID to close: ";
    cin >> Id2;

    // Search for the account using the provided ID
    for (int i = 0; i < accountCount; i++) 
    {
        if (accountIds[i] == Id2) 
        {
            // Shift all accounts after the closed account one position to the left
            for (int j = i; j < accountCount - 1; j++) 
            {
                accountIds[j] = accountIds[j + 1];
                accountPasswords[j] = accountPasswords[j + 1];
                accountBalances[j] = accountBalances[j + 1];
                accountNames[j] = accountNames[j + 1];
            }

            // Decrement the account count
            accountCount--;
            cout << "Account closed successfully.\n";
            return;
        }
    }

    // If the account is not found
    cout << "Account not found.\n";
}

// Main function
int main() 
{
    int choice;

    // Display the main menu repeatedly
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

        // Handle the user's choice
        switch (choice) {
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
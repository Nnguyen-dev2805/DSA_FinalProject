// Class Bank Account

#pragma once

#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
public:
    int accountID;
    string accountHolderName;
    string bankName;
    double balance;

public:
    BankAccount()
    {
        this->accountID = 0;
        this->accountHolderName = "";
        this->bankName = "";
        this->balance = 0.0;
    }

    BankAccount(int accountID, string accountHolderName, string bankName, double balance)
    {
        this->accountID = accountID;
        this->accountHolderName = accountHolderName;
        this->bankName = bankName;
        this->balance = balance;
    }

    BankAccount &operator=(const BankAccount &other)
    {
        if (this == &other)
            return *this; 

        this->accountID = other.accountID;
        this->accountHolderName = other.accountHolderName;
        this->bankName = other.bankName;
        this->balance = other.balance;

        return *this; 
    }

    bool operator<(const BankAccount &other) const
    {
        return this->accountID < other.accountID;
    }

    bool operator>(const BankAccount &other) const
    {
        return this->accountID > other.accountID;
    }

    bool operator==(const BankAccount &other) const
    {
        return this->accountID == other.accountID;
    }

    bool operator<=(BankAccount &other) const
    {
        return this->accountID <= other.accountID;
    }

    bool operator!=(BankAccount &other) const
    {
        return this->accountID != other.accountID;
    }

    int getAccountID()
    {
        return this->accountID;
    }

    double getBalance()
    {
        return this->balance;
    }

    string getBankName()
    {
        return this->bankName;
    }

    void setBalance(double newBalance)
    {
        this->balance = newBalance;
    }

    void enterValue()
    {
        cout << "Enter AccountID: ";
        cin >> this->accountID;
        cin.ignore();
        cout << "Enter Holder Name: ";
        getline(cin, this->accountHolderName);
        cout << "Enter Bank Name: ";
        getline(cin, this->bankName);
        cout << "Enter Balance: ";
        cin >> this->balance;
    }

    void display()
    {
        cout << "ID: " << this->accountID << endl;
        cout << "Holder Name: " << this->accountHolderName << endl;
        cout << "Bank Name: " << this->bankName << endl;
        cout << "Balance: " << this->balance << endl<<endl;
    }
};
//
//  DebitCard.cpp
//  Debit Card Project
//
//  Created by Blake Williams on 6/26/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include "DebitCard.h"
#include <iostream>

using namespace std;

DebitCard::DebitCard(){
    totalDeposits = 0;
    totalTransactions = 0;
    accountBalance = 0;
}

DebitCard::~DebitCard(){
    totalDeposits = totalTransactions = accountBalance = 0;
}

double DebitCard::Deposit(double deposit){
    accountBalance += deposit;
    totalDeposits += deposit;
    return accountBalance;
}

double DebitCard::PostTransaction(int idNumber, std::string date, std::string description, double amount){
    Transaction temp = Transaction(idNumber, date, description, amount);
    transactions.push_back(temp);
    accountBalance -= amount;
    totalTransactions++;
    return accountBalance;
}

bool DebitCard::ClearTransaction(int idNumber){
    for (int i=0;i<transactions.size();i++){
        if (transactions.at(i).idNumber == idNumber){
            transactions.at(i).cleared = true;
            return true;
        }
    }
    return false;
}

void DebitCard::DisplayActivity(){
    cout << fixed;
    cout.precision(2);
    cout << "total transactions: " << totalTransactions << endl;
    cout << "total deposits: $" << totalDeposits << endl;
    cout << "account balance: $" << accountBalance << endl << endl;
    cout << "List of cleared transactions: " << endl;
    for (int i=0;i<transactions.size();i++){
        Transaction tempTrans = transactions.at(i);
        if (tempTrans.cleared){
            cout << tempTrans.date << "   $";
            cout.width(7);
            cout << left << tempTrans.amount << tempTrans.description << endl;
        }
    }
    cout << '\n' << "List of pending transactions:  " << endl;
    for (int i=0;i<transactions.size();i++){
        Transaction tempTrans = transactions.at(i);
        if (!tempTrans.cleared){
            cout << tempTrans.date << "   $";
            cout.width(7);
            cout << left << tempTrans.amount << tempTrans.description << endl;
        }
    }
}

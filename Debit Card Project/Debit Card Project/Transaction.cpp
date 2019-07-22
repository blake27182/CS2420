//
//  Transaction.cpp
//  Debit Card Project
//
//  Created by Blake Williams on 6/26/19.
//  Copyright © 2019 Blake Williams. All rights reserved.
//

#include "Transaction.h"

Transaction::Transaction(int transactionID, std::string date, std::string description, double amount){
    idNumber = transactionID;
    this->date = date;
    this->description = description;
    this->amount = amount;
    cleared = false;
}


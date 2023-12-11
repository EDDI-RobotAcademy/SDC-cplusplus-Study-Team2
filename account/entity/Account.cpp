//
// Created by eddi on 23. 12. 6.
//

#include "Account.h"


Account::Account(const std::string& account_id, const std::string& password)
        : account_id(account_id),
          password(password),
          created_at(std::chrono::system_clock::now()),
          updated_at(created_at) { }


void Account::printAccountInfo() const {
    std::cout << ", Account_id: " << account_id
              << ", Password: " << password
              << ", Created At: " << std::chrono::system_clock::to_time_t(created_at)
              << ", Updated At: " << std::chrono::system_clock::to_time_t(updated_at) << std::endl;
}

std::string Account::getAccount_id() {
    return account_id;
}

std::string Account::getPassword() {
    return password;
}
//
// Created by eddi on 23. 12. 6.
//

#ifndef YOUNGCHANHWANG_ACCOUNT_H
#define YOUNGCHANHWANG_ACCOUNT_H

#include <string>
#include <chrono>
#include <iostream>

class Account {
private:
    std::string account_id;
    std::string password;

    std::chrono::system_clock::time_point created_at;
    std::chrono::system_clock::time_point updated_at;

public:
    Account(const std::string& account_id, const std::string& password);
    void printAccountInfo() const;


    std::string getAccount_id();
    std::string getPassword();
};

#endif //YOUNGCHANHWANG_ACCOUNT_H

//
// Created by eddi on 23. 12. 6.
//

#ifndef YOUNGCHANHWANG_ACCOUNTREPOSITORY_H
#define YOUNGCHANHWANG_ACCOUNTREPOSITORY_H

#include <vector>
#include <string>
#include "../entity/Account.h"

class AccountRepository {
public:
    virtual ~AccountRepository() = default;
    virtual bool createAccount(Account *account) = 0;
    virtual bool checkAccount(std::string account_id, std::string password) = 0;


};

#endif //YOUNGCHANHWANG_ACCOUNTREPOSITORY_H

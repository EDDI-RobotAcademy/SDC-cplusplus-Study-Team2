
//
// Created by eddi on 23. 12. 6.
//

#ifndef YOUNGCHANHWANG_ACCOUNTREPOSITORYIMPL_H
#define YOUNGCHANHWANG_ACCOUNTREPOSITORYIMPL_H

#include <memory>
#include "AccountRepository.h"

#include "../entity/LoginAccount.h"
#include "../service/request/AccountLoginRequest.h"


class AccountRepositoryImpl : public AccountRepository {
private:
    std::shared_ptr<AccountLoginRequest> accountLoginRequest;

public:
    bool createAccount(Account *account) override;
    bool checkAccount(std::string account_id, std::string password) override;

};

#endif //YOUNGCHANHWANG_ACCOUNTREPOSITORYIMPL_H

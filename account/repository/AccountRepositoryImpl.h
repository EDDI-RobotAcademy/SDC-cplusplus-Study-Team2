
//
// Created by eddi on 23. 12. 6.
//

#ifndef YOUNGCHANHWANG_ACCOUNTREPOSITORYIMPL_H
#define YOUNGCHANHWANG_ACCOUNTREPOSITORYIMPL_H

#include <memory>
#include "AccountRepository.h"
#include "../service/request/AccountRequestLogin.h"
#include "../entity/LoginAccount.h"


class AccountRepositoryImpl : public AccountRepository {
private:
    std::shared_ptr<AccountRequestLogin> accountRequestLogin;

public:
    void createAccount() override;
    void checkAccount() override;

};

#endif //YOUNGCHANHWANG_ACCOUNTREPOSITORYIMPL_H

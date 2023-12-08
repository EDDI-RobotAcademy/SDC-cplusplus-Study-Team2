//
// Created by eddi on 23. 12. 7.
//

#ifndef YOUNGCHANHWANG_ACCOUNTREQUESTLOGIN_H
#define YOUNGCHANHWANG_ACCOUNTREQUESTLOGIN_H

#include <string>
#include <vector>
#include "../../entity/LoginAccount.h"

class AccountRequestLogin {
private:
    std::string id;
    std::string password;

public:
    LoginAccount getIdPw();
};

#endif //YOUNGCHANHWANG_ACCOUNTREQUESTLOGIN_H

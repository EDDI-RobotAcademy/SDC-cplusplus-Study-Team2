//
// Created by eddi on 23. 12. 7.
//
#include "AccountRequestLogin.h"
#include "../../../ui/console/user_keyboard/user_keyboard_input.h"



LoginAccount AccountRequestLogin::getIdPw()
{
    std::cout<<"AccountRequestLogin" << std::endl;
    LoginAccount a;

    std::cout << "아이디입력" << std::endl;
    a.account_id = "아이디";
    std::cout << "비밀번호입력" << std::endl;
    a.password = "비밀번호";
    return a;
}
//
// Created by eddi on 23. 12. 5.
//

#ifndef CLASS_TEST_BOARDADAPTER_H
#define CLASS_TEST_BOARDADAPTER_H

#include "request/RequestAccountUidToAccountNameForm.h"

class BoardAdapter {
public:
    BoardAdapter() = default;
    ~BoardAdapter()= default;
    unsigned int requestAccountNameToAccountAdapter(unsigned int _accountUid);
};


#endif //CLASS_TEST_BOARDADAPTER_H

//
// Created by eddi on 23. 12. 4.
//

#ifndef CLASS_TEST_CONSOLEUISERVICE_H
#define CLASS_TEST_CONSOLEUISERVICE_H

#include <vector>

/*
#include "../handler/create/UiServiceCreateHandler.h"
#include "../handler/exit/UiServiceExitHandler.h"
#include "../handler/list/UiServiceListHandler.h"
#include "../handler/modify/UiServiceModifyHandler.h"
#include "../handler/read/UiServiceReadHandler.h"
#include "../handler/remove/UiServiceRemoveHandler.h"
*/

#include "../../../board/entity/Board.h"

class ConsoleUiService {
public:
    virtual ~ConsoleUiService() = default;
    virtual Board *creatPost() = 0;
    virtual void postExit () = 0;
    virtual void postList () = 0;
    virtual void postModify () = 0;
    virtual void postRead () = 0;
    virtual void postRemove () = 0;
};

#endif //CLASS_TEST_CONSOLEUISERVICE_H

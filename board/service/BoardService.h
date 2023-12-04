//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDSERVICE_H
#define CLASS_TEST_BOARDSERVICE_H

#include <vector>
#include "response/BoardResponseList.h"

class BoardService {
public:
    // 가상함수 : 존재하지만 존재하지 않는 것...
    // 앞으로 만들거긴 한데, 지금은 선언만 해둘
    virtual ~BoardService() = default;
    virtual std::vector<Board> list() = 0;
    virtual Board read(int) = 0;
//    virtual std::vector<BoardResponse> write() = 0;
//    virtual std::vector<BoardResponse> edit() = 0;
//    virtual void remove() = 0;
};

#endif //CLASS_TEST_BOARDSERVICE_H

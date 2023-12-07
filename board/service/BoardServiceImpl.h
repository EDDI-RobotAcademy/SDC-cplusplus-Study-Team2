//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDSERVICEIMPL_H
#define CLASS_TEST_BOARDSERVICEIMPL_H


#include <vector>
#include <memory>
#include "response/BoardResponseList.h"
#include "BoardService.h"
#include "../repository/BoardRepository.h"

class BoardServiceImpl : public BoardService {
private:
    std::shared_ptr<BoardRepository> boardRepository;

public:
    BoardServiceImpl(std::shared_ptr<BoardRepository> boardRepository);
    std::vector<Board> list() override;
    Board read(int) override;
    void write(BoardRequestFormWrite) override;
    void edit(BoardRequestFormEdit) override;
    void remove(int) override;
};


#endif //CLASS_TEST_BOARDSERVICEIMPL_H

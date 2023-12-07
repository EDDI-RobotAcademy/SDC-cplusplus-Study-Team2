//
// Created by eddi on 23. 11. 30.
//

#ifndef CLASS_TEST_BOARDREPOSITORYIMPL_H
#define CLASS_TEST_BOARDREPOSITORYIMPL_H


#include "BoardRepository.h"

class BoardRepositoryImpl : public BoardRepository {

public:
    std::vector<Board> findAll() override;
    Board findPost(int) override;
    void writePost(Board) override;
    void editPost(BoardRequestFormEdit) override;
    void removePost(int) override;
};


#endif //CLASS_TEST_BOARDREPOSITORYIMPL_H

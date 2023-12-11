//
// Created by eddi on 23. 12. 8.
//
#include <iostream>
#include <memory>

#include "ConsoleUiController.h"

#include "../../../board/controller/BoardController.h"
#include "../../../board/service//BoardServiceImpl.h"
#include "../../../board/repository/BoardRepository.h"
#include "../../../board/repository/BoardRepositoryImpl.h"

ConsoleUiController::ConsoleUiController(std::shared_ptr<ConsoleUiService> consoleUiService) : consoleUiService(consoleUiService) {}

void ConsoleUiController::uiEngine() {
    std::cout << "ConsoleUiController: uiEngine" << std::endl;
    consoleUiService->makeUiPrint();
}

void ConsoleUiController::uiBoardWrite() {
    RequestToWrite *requestToWrite;
    requestToWrite = consoleUiService->makeRequestToWriteForm();

    auto boardRepository = std::make_shared<BoardRepositoryImpl>();
    auto boardService = std::make_shared<BoardServiceImpl>(boardRepository);
    auto boardController = std::make_shared<BoardController>(boardService);
    boardController->boardWrite(requestToWrite);
}
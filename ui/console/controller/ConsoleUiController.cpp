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
#include "../../../board/entity/manager/BoardManager.h"
#include "../../../account/controller/AccountController.h"
#include "../../../account/service/AccountServiceImpl.h"
#include "../../../account/repository/AccountRepositoryImpl.h"

bool isLogin = false;
bool isQuit = false;

ConsoleUiController::ConsoleUiController(std::shared_ptr<ConsoleUiService> consoleUiService) : consoleUiService(consoleUiService) {
    initTables();

    std::cout << "연결됐다요" << std::endl;
}


void ConsoleUiController::uiEngine() {
    std::cout << "ConsoleUiController: uiEngine" << std::endl;
    boardManager.startBoard();
    startApplication();
  //  consoleUiService->makeUiAccountPrint();



}

void ConsoleUiController::initTables(){
    consoleBoardCommandTable[BOARD_READ] = [this] { uiBoardRead(); };
    consoleBoardCommandTable[BOARD_WRITE] = [this] { uiBoardWrite(); };
    consoleBoardCommandTable[BOARD_EDIT] = [this] { uiBoardEdit(); };
    consoleBoardCommandTable[BOARD_REMOVE] = [this] { uiBoardRemove(); };
    consoleBoardCommandTable[UI_BOARD_EXIT] = [this] { uiExit(); };

    consoleAccountCommandTable[ACCOUNT_REGISTER] = [this]{uiAccountRegister();};
    consoleAccountCommandTable[LOG_IN] = [this]{uiAccountLogin();};
    consoleAccountCommandTable[UI_ACCOUNT_EXIT] = [this]{uiExit();};
}

void ConsoleUiController::uiAccountLogin() {
    AccountLoginRequestForm *accountLoginRequestForm = consoleUiService->makeAccountRequestForm();
    AccountLoginResponseForm *accountLoginResponseForm;

    auto accountRepository = std::make_shared<AccountRepositoryImpl>();
    auto accountService = std::make_shared<AccountServiceImpl>(accountRepository);
    auto accountController = std::make_shared<AccountController>(accountService);

    accountLoginResponseForm = accountController->accountLogin(accountLoginRequestForm);
    if (!accountLoginResponseForm->getLoginSuccess()) {
        std::cout << "등록된 회원 정보가 없습니다." << std::endl;
    }
    else{
        std::cout << "로그인에 성공했습니다." << std::endl;
        isLogin = true;
    }
}

void ConsoleUiController::uiBoardRead() {
    int boardNo = consoleUiService->makeRequestToReadForm();
    auto boardRepository = std::make_shared<BoardRepositoryImpl>();
    auto boardService = std::make_shared<BoardServiceImpl>(boardRepository);
    auto boardController = std::make_shared<BoardController>(boardService);

    ResponseRead *responseRead = boardController->boardRead(boardNo);
    std::cout << "제목: " << responseRead->getTitle() << std::endl;
    std::cout << "작성자: " << responseRead->getWriter() << std::endl;
    std::cout << "내용: " << responseRead->getContent() << std::endl;
}

void ConsoleUiController::uiBoardWrite() {
    RequestToWrite *requestToWrite;
    requestToWrite = consoleUiService->makeRequestToWriteForm();

    auto boardRepository = std::make_shared<BoardRepositoryImpl>();
    auto boardService = std::make_shared<BoardServiceImpl>(boardRepository);
    auto boardController = std::make_shared<BoardController>(boardService);
    boardController->boardWrite(requestToWrite);
}

void ConsoleUiController::uiBoardEdit() {
    RequestToEdit *requestToEdit;
    requestToEdit = consoleUiService->makeRequestToEditForm();

    auto boardRepository = std::make_shared<BoardRepositoryImpl>();
    auto boardService = std::make_shared<BoardServiceImpl>(boardRepository);
    auto boardController = std::make_shared<BoardController>(boardService);
    boardController->boardEdit(requestToEdit);
}

void ConsoleUiController::uiBoardRemove() {
    int boardNo = consoleUiService->makeRequestToDeleteForm();
    auto boardRepository = std::make_shared<BoardRepositoryImpl>();
    auto boardService = std::make_shared<BoardServiceImpl>(boardRepository);
    auto boardController = std::make_shared<BoardController>(boardService);
    boardController->boardRemove(boardNo);
}


void ConsoleUiController::uiExit() {
    std::cout << "즉시 종료합니다. 사요나라." << std::endl;
    isQuit = true;
    exit(0);
}

void ConsoleUiController::startApplication(){
    while (!isLogin && !isQuit){
        consoleUiService->makeUiAccountPrint();
        consoleAccountCommandTable[getUserCommandInput()]();
    }
    while (!isQuit){
        consoleUiService->makeUiBoardPrint();
        consoleBoardCommandTable[getUserCommandInput()]();

    }
}

int ConsoleUiController::getUserCommandInput() {
    // 사용자에게 입력 받기
    //consoleUiService->makeUiBoardPrint();

    std::string inputKey;
    std::getline(std::cin, inputKey);
    // 입력 값을 정수로 변환
    return std::stoi(inputKey);
}

void ConsoleUiController::uiAccountRegister() {

}

//
// Created by eddi on 23. 12. 4.
//

#include "console_window.h"
#include "../user_keyboard/user_keyboard_input.h"
#include <memory>
#include "../../../board/controller/BoardController.h"
#include "../../../board/service/BoardServiceImpl.h"
#include "../../../board/repository/BoardRepository.h"
#include "../../../board/repository/BoardRepositoryImpl.h"
#include "../user_keyboard/user_keyboard_input.h"
#include "../service/handler/create/UiServiceCreateHandler.h"

#include <string>
#include <iostream>
#include <cstdlib>

void console_window::start_console_ui_window()
{
    //board_api_create_request_form *create_request_form;
    void *request_form;
    void *response_form;

    int user_choice_command_number;
    bool player_enter_quit = false;

    std::cout << "start ui loop" << std::endl;
    auto boardRepository = std::make_shared<BoardRepositoryImpl>();
    auto boardService = std::make_shared<BoardServiceImpl>(boardRepository);
    auto boardController = std::make_shared<BoardController>(boardService);
    boardController->boardList();

    while (!player_enter_quit)
    {
        user_choice_command_number = user_choice_number_for_board_command();
        if(user_choice_command_number == 1)
        {
            UiServiceCreateHandler _uiServiceCreateHandler;
            _uiServiceCreateHandler.getCreatPost();

        }
    }
}

int console_window::user_choice_number_for_board_command()
{
    std::string keyboard_input = { 0 };

    std::string command_message = "0번. 게시물 전체 조회\n"
                             "1번. 게시물 작성\n"
                             "2번. 게시물 읽기\n"
                             "3번. 게시물 수정\n"
                             "4번. 게시물 삭제\n"
                             "5번. 종료\n";
    user_keyboard_input _userKeyboardInput;
    _userKeyboardInput.get_user_keyboard_input_with_message(command_message, keyboard_input);

    return atoi(keyboard_input.c_str());
}

console_window::console_window() {

}

console_window::~console_window() {

}

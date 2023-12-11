//
// Created by eddi on 23. 12. 8.
//

#ifndef CPP_GTEST_CONSOLEUICONTROLLERCOMMAND_H
#define CPP_GTEST_CONSOLEUICONTROLLERCOMMAND_H

//enum class ConsoleUiControllerCommand {
//    ACCOUNT_REGISTER,
//    SIGN_IN,
//    SIGN_OUT,
//    //BOARD_LIST,
//   // BOARD_WRITE,
//   // BOARD_READ,
//   // BOARD_EDIT,
//    //BOARD_REMOVE,
//    UI_EXIT,
//    UI_COMMAND_END
//};

enum ConsoleUiAccountCommand {
    LOG_IN,
    ACCOUNT_REGISTER,

    UI_ACCOUNT_EXIT,
    NUM_ACCOUNT_COMMANDS
};

enum ConsoleBoardCommand{
    BOARD_LIST,
    BOARD_WRITE,
    BOARD_READ,
    BOARD_EDIT,
    BOARD_REMOVE,
    UI_BOARD_EXIT,
    NUM_BOARD_COMMANDS,
};

#endif //CPP_GTEST_CONSOLEUICONTROLLERCOMMAND_H

//
// Created by eddi on 23. 12. 8.
//
#include <iostream>

#include "ConsoleUiController.h"

ConsoleUiController::ConsoleUiController(std::shared_ptr<ConsoleUiService> consoleUiService) : consoleUiService(consoleUiService) {}

void ConsoleUiController::uiEngine() {
    std::cout << "ConsoleUiController: uiEngine" << std::endl;
    consoleUiService->makeUiPrint();
}
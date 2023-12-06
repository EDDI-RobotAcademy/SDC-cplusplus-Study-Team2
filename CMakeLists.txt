cmake_minimum_required(VERSION 3.26)
project(class_test)

set(CMAKE_CXX_STANDARD 17)

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})

add_executable(class_test main.cpp
        board/controller/BoardController.cpp
        board/controller/BoardController.h
        board/service/BoardService.h
        board/service/BoardServiceImpl.cpp
        board/service/BoardServiceImpl.h
        board/entity/Board.cpp
        board/entity/Board.h
        board/repository/BoardRepository.h
        mysql/DbProcess.cpp
        mysql/DbProcess.h
        board/repository/BoardRepositoryImpl.cpp
        board/repository/BoardRepositoryImpl.h
        board/manager/BoardManager.cpp
        board/manager/BoardManager.h
        board/service/response/BoardResponseList.cpp
        board/service/response/BoardResponseList.h
        board/service/response/BoardResponseRead.cpp
        board/service/response/BoardResponseRead.h
        board/service/request/BoardRequestFormWrite.cpp
        board/service/request/BoardRequestFormWrite.h
        ui/console/service/ConsoleUiService.h
        ui/console/service/ConsoleUiServiceImpl.cpp
        ui/console/service/ConsoleUiServiceImpl.h
        ui/console/user_keyboard/user_keyboard_input.cpp
        ui/console/window/console_window.cpp
        ui/console/repository/ConsoleUiRepository.h
        ui/console/repository/ConsoleUiRepository.h
        ui/console/controller/ConsoleUiController.cpp
        ui/console/controller/ConsoleUiController.h
)

target_include_directories(class_test PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(class_test PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})
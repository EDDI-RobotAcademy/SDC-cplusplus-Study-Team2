cmake_minimum_required(VERSION 3.26)
project(cpp_gtest)
#project(SDC-cplusplus-Study-Team2)
# G
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_STANDARD 17)
# G
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

find_package(GTest REQUIRED)

# G
if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Google Test를 찾을 수 없습니다. Google Test를 설치하세요.")
endif()

enable_testing()
# 폴더만?
file(GLOB CPP_SOURCES
        "board/*.cpp"
        #"g_sample/*.cpp"
        "ui/*.cpp"
        "mysql/*.cpp"
)
# 진짜 돌려야 하는애?
file(GLOB CPP_TEST_SOURCES
        "tests/*.cpp"
        #"tests/add/*.cpp"
        "board/controller/BoardController.cpp"
        "board/controller/BoardController.h"
        "board/service/BoardService.h"
        "board/service/BoardServiceImpl.cpp"
        "board/service/BoardServiceImpl.h"
        "board/entity/Board.cpp"
        "board/entity/Board.h"
        "board/repository/BoardRepository.h"
        "mysql/DbProcess.cpp"
        "mysql/DbProcess.h"
        "board/repository/BoardRepositoryImpl.cpp"
        "board/repository/BoardRepositoryImpl.h"
        "board/manager/BoardManager.cpp"
        "board/manager/BoardManager.h"
        "board/service/response/BoardResponseList.cpp"
        "board/service/response/BoardResponseList.h"
        "board/service/response/BoardResponseRead.cpp"
        "board/service/response/BoardResponseRead.h"
        "board/service/request/BoardRequestFormWrite.cpp"
        "board/service/request/BoardRequestFormWrite.h"
        "ui/console/service/UiService.h"
        "ui/console/service/UiServiceImpl.cpp"
        "ui/console/service/UiServiceImpl.h"
        "ui/console/user_keyboard/user_keyboard_input.cpp"
        "ui/console/window/console_window.cpp"
        "ui/console/service/handler/remove/UiServiceRemoveHandler.cpp"
        "ui/console/service/handler/read/UiServiceReadHandler.cpp"
        "ui/console/service/handler/modify/UiServiceModifyHandler.cpp"
        "ui/console/service/handler/list/UiServiceListHandler.cpp"
        "ui/console/service/handler/exit/UiServiceExitHandler.cpp"
        "ui/console/service/handler/create/UiServiceCreateHandler.cpp"
)

file(GLOB MAIN_SOURCES
        "*.cpp"
)

add_executable(
        cpp_gtest
        ${CPP_SOURCES}
        ${CPP_TEST_SOURCES}
        ${MAIN_SOURCES}
       # tests/test_main.cpp
        #tests/gogo/gtest_main.cpp
)

#include(FindPkgConfig)
#pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)
#
#link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})
#
#add_executable(
#        class_test main.cpp
#        board/controller/BoardController.cpp
#        board/controller/BoardController.h
#        board/service/BoardService.h
#        board/service/BoardServiceImpl.cpp
#        board/service/BoardServiceImpl.h
#        board/entity/Board.cpp
#        board/entity/Board.h
#        board/repository/BoardRepository.h
#        mysql/DbProcess.cpp
#        mysql/DbProcess.h
#        board/repository/BoardRepositoryImpl.cpp
#        board/repository/BoardRepositoryImpl.h
#        board/manager/BoardManager.cpp
#        board/manager/BoardManager.h
#        board/service/response/BoardResponseList.cpp
#        board/service/response/BoardResponseList.h
#        board/service/response/BoardResponseRead.cpp
#        board/service/response/BoardResponseRead.h
#        board/service/request/BoardRequestFormWrite.cpp
#        board/service/request/BoardRequestFormWrite.h
#        ui/console/service/UiService.h
#        ui/console/service/UiServiceImpl.cpp
#        ui/console/service/UiServiceImpl.h
#        ui/console/user_keyboard/user_keyboard_input.cpp
#        ui/console/window/console_window.cpp
#        ui/console/service/handler/remove/UiServiceRemoveHandler.cpp
#        ui/console/service/handler/read/UiServiceReadHandler.cpp
#        ui/console/service/handler/modify/UiServiceModifyHandler.cpp
#        ui/console/service/handler/list/UiServiceListHandler.cpp
#        ui/console/service/handler/exit/UiServiceExitHandler.cpp
#        ui/console/service/handler/create/UiServiceCreateHandler.cpp
#)
# G
add_library(logic_lib ${CPP_SOURCES})
#target_include_directories(class_test PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
#MYSQL 추가 + G

add_executable(every_unit_test ${CPP_TEST_SOURCES} "tests/test_main.cpp"  ${CPP_SOURCES})
target_link_libraries(every_unit_test PRIVATE ${GTEST_LIBRARIES} pthread logic_lib)
target_link_libraries(class_test mysqlclient)
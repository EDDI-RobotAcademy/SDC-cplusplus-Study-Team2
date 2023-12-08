cmake_minimum_required(VERSION 3.10)
project(gogo)

set(CMAKE_CXX_STANDARD 17)

# 돌리고자 하는 경로를 지정합니다.
file(GLOB CPP_SOURCES
        "../../board/entity/Board.cpp"
        "../../board/entity/manager/BoardManager.cpp"
        "../../board/repository/BoardRepositoryImpl.h"
        "../../board/service/BoardServiceImpl.h"
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} gtest_main.cpp ${CPP_SOURCES}
        ../../board/controller/BoardController.cpp
        ../../board/repository/BoardRepositoryImpl.cpp
        ../../board/service/BoardServiceImpl.cpp
        ../../mysql/DbProcess.cpp
        ../../board/service/request/BoardRequestFormWrite.cpp
        ../../board/service/request/BoardRequestFormEdit.cpp
        ../../board/controller/request/ReqeustToBoardControllerFindPostToEdit.cpp
        ../../board/controller/request/ReqeustToBoardControllerFindPostToEdit.h)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)
include_directories(${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread ${LIBMYSQLCLIENT_LIBRARIES})
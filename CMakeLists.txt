cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)

add_executable(Tetris
    main.cpp
    src/Game.cpp
    src/Piece.cpp
    src/Board.cpp
    
)

target_link_libraries(Tetris sfml-graphics sfml-window sfml-system)
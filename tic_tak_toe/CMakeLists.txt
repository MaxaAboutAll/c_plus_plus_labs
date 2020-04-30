cmake_minimum_required(VERSION 3.15)
project(tic_tak_toe)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(tic_tak_toe main.cpp PlayField.cpp PlayField.h TreeNode.cpp TreeNode.h XOPlayer.cpp XOPlayer.h)
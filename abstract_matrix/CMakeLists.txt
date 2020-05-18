cmake_minimum_required(VERSION 3.16)
project(abstract_matrix)

set(CMAKE_CXX_STANDARD 14)

add_executable(abstract_matrix main.cpp MatrixBase.cpp MatrixBase.h Matrix2D.cpp Matrix2D.h Matrix3D.cpp Matrix3D.h)
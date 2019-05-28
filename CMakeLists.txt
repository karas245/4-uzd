# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.13)
project(4-uzd)



set(CMAKE_CXX_STANDARD 14)


add_executable(4-uzd
        main.cpp
        classVector.cpp
        classVector.h
	fun.h
        )

cmake_minimum_required(VERSION 2.8.4)
project(MultithreadDeLaMortOfTheLoveOfTheKissOfTheDeath)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcurl")
set(SOURCE_FILES main.cpp
Network/ApiServer
)

add_executable(MultithreadDeLaMortOfTheLoveOfTheKissOfTheDeath ${SOURCE_FILES})
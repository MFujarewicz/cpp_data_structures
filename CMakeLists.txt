cmake_minimum_required(VERSION 3.22.1)
project(cpp_projekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_projekt src/main.cpp
        src/circularBuffer.hpp
        src/circularBuffer.ipp
        src/queue.hpp
        src/queue.ipp
        src/hashMap.ipp
        src/hashMap.hpp
)

cmake_minimum_required(VERSION 3.29.6)
project(Tpsit_Project_Work)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tpsit_Project_Work main.cpp
        include/Impianto.h
        src/Impianto.cpp
        include/Serra.h
        src/Serra.cpp
        include/Time.h
        src/Time.cpp)

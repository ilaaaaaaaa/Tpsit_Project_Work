cmake_minimum_required(VERSION 3.29.6)
project(Tpsit_Project_Work)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tpsit_Project_Work main.cpp
        include/Impianto.h
        src/Impianto.cpp
        include/Serra.h
        src/Serra.cpp
        include/Time.h
        src/Time.cpp
        include/Tropicale.h
        include/Desertica.h
        include/Mediterranea.h
        include/Alpina.h
        include/Carnivora.h
        src/Mediterranea.cpp
        src/Alpina.cpp
        src/Carnivora.cpp
        src/Desertica.cpp
        src/Tropicale.cpp
)

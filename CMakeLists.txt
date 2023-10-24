cmake_minimum_required(VERSION 3.22)
project(ayp2_tp2_solucion)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Werror -Wconversion)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")
set(CXXFLAGS "-Wall -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

include_directories(include)
include_directories(src)

add_executable(ayp2_tp2_solucion
        src/Item.cpp
        src/Inventario.cpp
        src/Evento.cpp
        main.cpp
        src/Menu.cpp
        src/Lector.cpp
        src/Destino.cpp
        include/Lista_de.hpp
        include/Nodo_de.hpp
        include/Cola.hpp
        include/Nodo.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "programa.exe")
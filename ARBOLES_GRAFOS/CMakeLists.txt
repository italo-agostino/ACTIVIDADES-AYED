cmake_minimum_required(VERSION 3.20)
project(ArbolesGrafos CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Crea un ejecutable por cada .cpp de esta carpeta
file(GLOB EJERCICIOS CONFIGURE_DEPENDS "*.cpp")
foreach(archivo ${EJERCICIOS})
    get_filename_component(nombre ${archivo} NAME_WE)
    add_executable(${nombre} ${archivo})
endforeach()
cmake_minimum_required(VERSION 3.12)
project(join_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include(CPack)

# Опции для статической линковки (если нужно)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)  # Используйте только если хотите статический рантайм

# Добавляем исполняемый файл
add_executable(join_server 
    main.cpp
)

set_target_properties(join_server PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

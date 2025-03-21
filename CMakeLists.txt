cmake_minimum_required(VERSION 3.12)
project(join_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "join_server")
set(CPACK_PACKAGE_VERSION "0.0.${PATCH_VERSION}")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <your@email.com>")
set(CPACK_PACKAGE_CONTACT "Your Name <your@email.com>")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libboost-test-dev")
set(CPACK_DEBIAN_FILE_NAME "DEB-DEFAULT")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-Linux")
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

cmake_minimum_required(VERSION 3.0.0)
project(fat32 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp
            fs/fat32.cpp
            br/boot_record.cpp
            util/util.cpp
    )

set(HEADERS fs/fat32.hpp
            br/boot_record.hpp
            util/util.hpp
)


add_executable(fat32 ${SOURCES} ${HEADERS})

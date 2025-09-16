cmake_minimum_required(VERSION 3.30)
project(Wasalni)

set(CMAKE_CXX_STANDARD 20)

# Add your source files here
add_executable(Wasalni
    main.cpp
    admin.cpp
    driver.cpp
    user.cpp
    RideManager.cpp
)

# Set output directories for executables and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Project settings
cmake_minimum_required(VERSION 3.14)
project(OnlineNim)

# Build settings
set(CMAKE_BUILD_TYPE "Debug")

# C++ settings
set(CMAKE_CXX_STANDARD 14) # 14+ required by GoogleTest
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Sanitize build settings
set(BUILD_TYPES "Debug" "Release")
if(NOT ("${CMAKE_BUILD_TYPE}" IN_LIST BUILD_TYPES))
    message(FATAL_ERROR "CMAKE_BUILD_TYPE not recognized: ${CMAKE_BUILD_TYPE} not in ${BUILD_TYPES}")
endif()

# CMake settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
make_directory("${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Find and configure GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
## For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Set sources, include directories and libraries
set(CPPSources
    "src/main.cpp"
    )
set(LINK_LIBRARIES GTest::gtest_main)
set(INCLUDE_DIRS)

# Build executable and link libraries
add_executable(OnlineNim ${CPPSources})
target_include_directories(OnlineNim PRIVATE ${INCLUDE_DIRS})
target_link_libraries(OnlineNim ${LINK_LIBRARIES})

include(GoogleTest)
gtest_discover_tests(OnlineNim)
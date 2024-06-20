# Project settings
cmake_minimum_required(VERSION 3.14)
project(OnlineNim)

# Build settings
set(CMAKE_BUILD_TYPE "Debug")

# C++ settings
set(CMAKE_CXX_STANDARD 17) # 17+ required by application, 14+ required by GoogleTest
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
set(TO_LINK)
set(TO_INCLUDE)

# Find and configure dependencies
## Find and configure SFML
set(SFML_ROOT_DIR "extlibs/SFML-2.5.1")
set(SFML_DIR "${SFML_ROOT_DIR}/lib/cmake/SFML")
if(WIN32)
    find_package(SFML COMPONENTS main network graphics window system REQUIRED)
else()
    find_package(SFML COMPONENTS network graphics window system REQUIRED)
endif()

if (WIN32)
    set(TO_LINK ${TO_LINK} sfml-main sfml-network sfml-graphics sfml-window sfml-system)
else()
    set(TO_LINK ${TO_LINK} sfml-network sfml-graphics sfml-window sfml-system)
endif()
set(TO_INCLUDE ${TO_INCLUDE} ${SFML_ROOT_DIR}/include)

## Find and configure GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
### For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

set(TO_LINK ${TO_LINK} GTest::gtest_main)

# Set sources, include directories and libraries
set(CPPSources
    "src/controller/AppController.cpp"
    "src/controller/MenuStates/GameMenuState.cpp"
    "src/controller/MenuStates/MainMenuState.cpp"
    "src/controller/MenuStates/HostMenuState.cpp"
    "src/controller/MenuStates/JoinMenuState.cpp"
    "src/controller/MenuContext.cpp"
    "src/controller/LocalStreamPlayer.cpp"
    "src/controller/LocalOnlinePlayer.cpp"
    "src/controller/RemoteOnlinePlayer.cpp"
    "src/model/GameState.cpp"
    "src/model/Move.cpp"
    "src/view/GameView.cpp"
    "src/main.cpp"
    )
set(LINK_LIBRARIES ${TO_LINK})
set(INCLUDE_DIRS ${TO_INCLUDE})

# Build executable and link libraries
add_executable(OnlineNim ${CPPSources})
target_include_directories(OnlineNim PRIVATE ${INCLUDE_DIRS})
target_link_libraries(OnlineNim ${LINK_LIBRARIES})

# include(GoogleTest)
# gtest_discover_tests(OnlineNim)

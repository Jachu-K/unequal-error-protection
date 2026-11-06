cmake_minimum_required(VERSION 3.20)
project(unequal_error_protection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

add_library(core
        src/bits.cpp
        src/random.cpp
        src/signal_io.cpp
        src/channel.cpp
        src/frame.cpp
        src/transmit.cpp
        src/codes.cpp
        src/hamming.cpp
        src/repetition.cpp
        src/sample.cpp
)
target_include_directories(core PUBLIC include)

if(MSVC)
    target_compile_options(core PRIVATE /W4)
else()
    target_compile_options(core PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE core)

include(FetchContent)
# doctest ma w sobie stare cmake_minimum_required; CMake 4.x bez tego odmawia
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
FetchContent_Declare(
        doctest
        GIT_REPOSITORY https://github.com/doctest/doctest.git
        GIT_TAG        v2.4.11
)
FetchContent_MakeAvailable(doctest)

# --- Testy ---
enable_testing()
add_executable(tests
        tests/test_bits.cpp
        tests/test_channel.cpp
        tests/test_signal.cpp
        tests/test_frame.cpp
        tests/test_hamming.cpp
        tests/test_repetition.cpp
        tests/test_sample.cpp
)
target_link_libraries(tests PRIVATE core doctest::doctest_with_main)
add_test(NAME tests COMMAND tests)
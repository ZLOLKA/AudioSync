#[[ Help
-DUSE_CHECK_FORMAT=0 for disable call clang-format --dry-run
]]

cmake_minimum_required(VERSION 3.26)

project(AudioSync VERSION 0.1 LANGUAGES CXX)

file(GLOB src_files 
    "./src/**/*.cpp" 
    "./src/*.cpp" 
    "./main.cpp"
)

if(NOT DEFINED USE_CHECK_FORMAT)
    set(USE_CHECK_FORMAT 1)
endif()
if(USE_CHECK_FORMAT)
    message("\n*** Start checking format process")
    file(GLOB h_files
        "./include/**/*.hpp"
        "./include/*.hpp"
    )

    execute_process(
        COMMAND clang-format --style=file --verbose --dry-run --Werror ${h_files} ${src_files}
        RESULT_VARIABLE result_format
    )
    if(${result_format})
        message(FATAL_ERROR "ERROR: Unformatted code file: for fix run\nclang-format --style=file -i ./path/to/problem/file")
    endif()
    message("*** End checking format process\n")
endif()

add_executable(AudioSync ${src_files})

target_include_directories(AudioSync PUBLIC "include/")
target_compile_options(AudioSync PUBLIC 
    -pedantic-errors -Werror -Wall -Wextra -Wpedantic -Wpedantic-macros
    -ftemplate-backtrace-limit=0
)

# Include yaml-cpp as static lib
add_subdirectory("third-party/yaml-cpp")
target_link_libraries(AudioSync PUBLIC yaml-cpp)


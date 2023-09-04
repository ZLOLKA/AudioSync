#[[ Help
-DUSE_CHECK_FORMAT=0 for disable call clang-format --dry-run
]]

cmake_minimum_required(VERSION 3.26)

project(AudioSync VERSION 0.1 LANGUAGES CXX)

file(GLOB src_files
    "./src/**/*.cpp"
    "./src/*.cpp"
)

if(NOT DEFINED NOEXCEPT_MODE)
    set(NOEXCEPT_MODE 0)
endif()

add_library(AudioSyncLib STATIC ${src_files})

target_include_directories(AudioSyncLib PUBLIC "include/")
target_compile_options(AudioSyncLib PRIVATE
    -Werror
)
target_compile_options(AudioSyncLib PUBLIC
    -pedantic-errors -Wall -Wextra -Wpedantic -Wpedantic-macros
    -ftemplate-backtrace-limit=0
)

message("\nNOEXCEPT_MODE=" ${NOEXCEPT_MODE}
    "\nIf cmake run with -DNOEXCEPT_MODE=-1 then all function marked noexcept(false)"
    " and add compile option -Wno-microsoft-exception-spec"
    "\nIf with -DNOEXCEPT_MODE=0 then noexcept(exp)"
    "\nIf with -DNOEXCEPT_MODE=1 then noexcept(true)"
    "\n")
target_compile_definitions(AudioSyncLib PUBLIC NOEXCEPT_MODE=${NOEXCEPT_MODE})
if(${NOEXCEPT_MODE} STREQUAL "-1")
    target_compile_options(AudioSyncLib PUBLIC
        -Wno-microsoft-exception-spec
    )
endif()

# Include yaml-cpp as static lib
add_subdirectory("third-party/yaml-cpp")
target_link_libraries(AudioSyncLib PUBLIC yaml-cpp)

add_executable(AudioSync "main.cpp")
target_link_libraries(AudioSync PUBLIC AudioSyncLib)

if(NOT DEFINED USE_TESTS)
    set(USE_TESTS 1)
endif()
message("USE_TESTS=" ${USE_TESTS} "\n")
if(USE_TESTS)
    set(test_target_name "AudioSync_tests")
    include("tests/cpp_tests/CMakeLists.txt")
    add_custom_command(TARGET ${test_target_name} POST_BUILD
        WORKING_DIRECTORY "${test_output_dir}/"
        COMMAND ${CMAKE_COMMAND} -E echo ""
        COMMAND ${CMAKE_COMMAND} -E echo "*** Start tests"
        COMMAND "${test_target_name}"
        COMMAND ${CMAKE_COMMAND} -E echo "*** End tests"
        COMMAND ${CMAKE_COMMAND} -E echo ""
    )
endif()

if(NOT DEFINED USE_CHECK_FORMAT)
    set(USE_CHECK_FORMAT 1)
endif()
if(USE_CHECK_FORMAT)
    message("\n*** Start checking format process")
    file(GLOB h_files
        "./include/**/*.hpp"
        "./include/*.hpp"
    )
    set(to_format_files
        "./main.cpp"
        ${h_files}
        ${src_files}
    )
    if(USE_TESTS)
        file(GLOB mock_files
            "${tests_dir}/gMocks/**/*_mock.hpp"
            "${tests_dir}/gMocks/*_mock.hpp"
        )
        file(GLOB test_h_files
            "${tests_dir}/include/**/*.hpp"
            "${tests_dir}/include/*.hpp"
        )
        list(APPEND to_format_files
            ${test_h_files}
            ${test_src_files}
            ${tests_files}
            ${mock_files}
        )
    endif()

    execute_process(
        COMMAND clang-format --style=file --verbose --dry-run --Werror ${to_format_files}
        RESULT_VARIABLE result_format
    )
    if(${result_format})
        message(FATAL_ERROR "ERROR: Unformatted code file:"
        "\nfor fix run"
        "\nclang-format --style=file -i ./path/to/problem/file"
        "\nor run cmake with -DUSE_CHECK_FORMAT=0 option (for ignoring this check)")
    endif()
    message("*** End checking format process\n")
endif()


# this is the build file for project 
# it is autogenerated by the xmake build system.
# do not edit by hand.

# project
cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0091 NEW)
project(syntaxAnalysis LANGUAGES CXX C)

# target
set(CMAKE_C_COMPILER "C:/Users/jyf/scoop/apps/mingw/current/bin/x86_64-w64-mingw32-gcc")
set(CMAKE_CXX_COMPILER "C:/Users/jyf/scoop/apps/mingw/current/bin/x86_64-w64-mingw32-g++")
add_executable(syntaxAnalysis "")
set_target_properties(syntaxAnalysis PROPERTIES OUTPUT_NAME "syntaxAnalysis")
set_target_properties(syntaxAnalysis PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/mingw/x86_64/release")
target_include_directories(syntaxAnalysis PRIVATE
    syntaxAnalysis/recursiveDescendingSubroutines/include
)
target_compile_options(syntaxAnalysis PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-m64>
    $<$<COMPILE_LANGUAGE:CXX>:-m64>
)
if(MSVC)
    target_compile_options(syntaxAnalysis PRIVATE $<$<CONFIG:Release>:-Ox -fp:fast>)
else()
    target_compile_options(syntaxAnalysis PRIVATE -O3)
endif()
if(MSVC)
else()
    target_compile_options(syntaxAnalysis PRIVATE -fvisibility=hidden)
endif()
if(MSVC)
    set_property(TARGET syntaxAnalysis PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
target_link_options(syntaxAnalysis PRIVATE
    -m64
)
target_sources(syntaxAnalysis PRIVATE
    syntaxAnalysis/recursiveDescendingSubroutines/src/main.cpp
    syntaxAnalysis/recursiveDescendingSubroutines/src/recursiveDescending.cpp
)

# target
set(CMAKE_C_COMPILER "C:/Users/jyf/scoop/apps/mingw/current/bin/x86_64-w64-mingw32-gcc")
set(CMAKE_CXX_COMPILER "C:/Users/jyf/scoop/apps/mingw/current/bin/x86_64-w64-mingw32-g++")
add_executable(wordAnalysis "")
set_target_properties(wordAnalysis PROPERTIES OUTPUT_NAME "wordAnalysis")
set_target_properties(wordAnalysis PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/mingw/x86_64/release")
target_include_directories(wordAnalysis PRIVATE
    wordAnalysis/include
)
target_compile_options(wordAnalysis PRIVATE
    $<$<COMPILE_LANGUAGE:C>:-m64>
    $<$<COMPILE_LANGUAGE:CXX>:-m64>
)
if(MSVC)
    target_compile_options(wordAnalysis PRIVATE $<$<CONFIG:Release>:-Ox -fp:fast>)
else()
    target_compile_options(wordAnalysis PRIVATE -O3)
endif()
if(MSVC)
else()
    target_compile_options(wordAnalysis PRIVATE -fvisibility=hidden)
endif()
if(MSVC)
    set_property(TARGET wordAnalysis PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
target_link_options(wordAnalysis PRIVATE
    -m64
)
target_sources(wordAnalysis PRIVATE
    wordAnalysis/src/FileUtil.cpp
    wordAnalysis/src/main.cpp
    wordAnalysis/src/WordAnalysis.cpp
)


cmake_minimum_required(VERSION 2.8)
project(CPSL_compiler)

find_package(BISON)
find_package(FLEX)

bison_target(Parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(Scanner Parser)

set(EXTRA_COMPILE_FLAGS "-g3 -std=c++14")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

set(CPSL_compiler_srcs
    main.cpp
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS} classes/Program.cpp classes/Const.cpp classes/Const.h classes/Const/ConstAssign.cpp classes/Const/ConstAssign.h classes/Const/ConstDecl.cpp classes/Const/ConstDecl.h classes/Program.cpp classes/Program.h classes/Callable/Callable.h classes/Callable/Function.cpp classes/Callable/Function.h classes/Callable/Procedure.cpp classes/Callable/Procedure.h includes.h classes/Type/TypeAssign.cpp classes/Type/TypeAssign.h classes/Type/TypeDecl.cpp classes/Type/TypeDecl.h)

include_directories(classes)

source_group("CPSL_compiler" FILES ${CPSL_compiler_srcs})

add_executable(CPSL_compiler ${CPSL_compiler_srcs})
target_link_libraries(CPSL_compiler ${BISON_LIBRARIES})
target_include_directories(CPSL_compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
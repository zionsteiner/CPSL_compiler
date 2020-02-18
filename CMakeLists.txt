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
    scanner.l
    symbol_table.hpp
    symbol_table.cpp
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS}
        classes/Expr/Expr.h
        classes/Expr/Const/Const.cpp
        classes/Expr/Const/Const.h
        classes/Type.cpp
        classes/Type.h
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Add.cpp
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Add.h
        classes/Expr/OpExpr/BinOpExpr/BinOpExpr.cpp
        classes/Expr/OpExpr/BinOpExpr/BinOpExpr.h
        classes/Expr/Const/IntConst.cpp
        classes/Expr/Const/IntConst.h
        classes/Expr/Const/ChrConst.cpp
        classes/Expr/Const/ChrConst.h
        classes/Expr/Const/StrConst.cpp
        classes/Expr/Const/StrConst.h
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Sub.cpp
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Sub.h
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Mult.cpp
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Mult.h
        classes/Expr/OpExpr/OpExpr.cpp
        classes/Expr/OpExpr/OpExpr.h
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Div.cpp
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Div.h
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/ArithBinOpExpr.h
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/ArithBinOpExpr.cpp
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Mod.cpp
        classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Mod.h
        classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/BoolBinOpExpr.h
        classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/BoolBinOpExpr.cpp
        classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Amp.cpp
        classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Amp.h classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Bar.cpp classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Bar.h classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/GEQ.cpp classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/GEQ.h classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/CmprBinOptExpr.cpp classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/CmprBinOptExpr.h classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/GT.cpp classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/GT.h classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/LEQ.cpp classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/LEQ.h classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/LT.cpp classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/LT.h classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/EQ.cpp classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/EQ.h classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/NEQ.cpp classes/Expr/OpExpr/BinOpExpr/CmprBinOptExpr/NEQ.h classes/Expr/OpExpr/UnaryOpExpr/UnaryMinus.cpp classes/Expr/OpExpr/UnaryOpExpr/UnaryMinus.h classes/Expr/OpExpr/UnaryOpExpr/Not.cpp classes/Expr/OpExpr/UnaryOpExpr/Not.h classes/Expr/Const/BoolConst.cpp classes/Expr/Const/BoolConst.h)
source_group("CPSL_compiler" FILES ${CPSL_compiler_srcs})

add_executable(CPSL_compiler ${CPSL_compiler_srcs})
target_link_libraries(CPSL_compiler ${BISON_LIBRARIES})
target_include_directories(CPSL_compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
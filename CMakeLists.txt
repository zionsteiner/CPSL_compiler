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
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS}
    classes/Expr/Expr.h
    classes/Expr/Const/Const.cpp
    classes/Expr/Const/Const.h
        classes/Type/Type.h
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
    classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Amp.h
    classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Bar.cpp
    classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Bar.h
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/GEQ.cpp
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/GEQ.h
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/CmprBinOpExpr.cpp
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/CmprBinOpExpr.h
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/GT.cpp
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/GT.h
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/LEQ.cpp
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/LEQ.h
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/LT.cpp
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/LT.h
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/EQ.cpp
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/EQ.h
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/NEQ.cpp
    classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/NEQ.h
    classes/Expr/OpExpr/UnaryOpExpr/UnaryMinus.cpp
    classes/Expr/OpExpr/UnaryOpExpr/UnaryMinus.h
    classes/Expr/OpExpr/UnaryOpExpr/Not.cpp
    classes/Expr/OpExpr/UnaryOpExpr/Not.h
    classes/Expr/Const/BoolConst.cpp
    classes/Expr/Const/BoolConst.h
    classes/Type/ArrayType.cpp
    classes/Type/ArrayType.h
    classes/Type/RecordType.cpp
    classes/Type/RecordType.h
    classes/Type/SimpleType.cpp
    classes/Type/SimpleType.h
    classes/List/List.h
    classes/List/StrList.h
    classes/List/StrList.cpp
    classes/List/ExprList.cpp
    classes/List/ExprList.h
    classes/Param.cpp classes/Param.h globals.cpp globals.h)

source_group("CPSL_compiler" FILES ${CPSL_compiler_srcs})

add_executable(CPSL_compiler ${CPSL_compiler_srcs})
target_link_libraries(CPSL_compiler ${BISON_LIBRARIES})
target_include_directories(CPSL_compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
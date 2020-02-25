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
    ${FLEX_Scanner_OUTPUTS}
        classes/Expr/OpExpr/UnaryOpExpr/Not.cpp
        classes/Expr/OpExpr/UnaryOpExpr/Not.h classes/Expr/LValue/LValue.cpp classes/Expr/LValue/LValue.h classes/Expr/LValue/DotExt.cpp classes/Expr/LValue/DotExt.h classes/Expr/LValue/IndexExt.cpp classes/Expr/LValue/IndexExt.h classes/Expr/LValue/Ext.h classes/List/DotOrIndexPlus.cpp classes/List/DotOrIndexPlus.h classes/Expr/OpExpr/UnaryOpExpr/UnaryOpExpr.cpp classes/Expr/OpExpr/UnaryOpExpr/UnaryOpExpr.h classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/ChrFunc.cpp classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/ChrFunc.h classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/OrdFunc.cpp classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/OrdFunc.h classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/SuccFunc.cpp classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/SuccFunc.h classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/PredFunc.cpp classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/PredFunc.h classes/List/ExprList.cpp classes/List/ExprList.h classes/Type/Primitive.cpp classes/Type/Primitive.h classes/Type/IntType.cpp classes/Type/IntType.h classes/Type/StrType.cpp classes/Type/StrType.h classes/Type/ChrConst.cpp classes/Type/ChrConst.h classes/Expr/ProcCall.cpp classes/Expr/ProcCall.h classes/Stmt/Stmt.h classes/Stmt/WriteStmt.cpp classes/Stmt/WriteStmt.h classes/Stmt/ReadStmt.cpp classes/Stmt/ReadStmt.h classes/Stmt/ReturnStmt.cpp classes/Stmt/ReturnStmt.h)

include_directories(classes)

source_group("CPSL_compiler" FILES ${CPSL_compiler_srcs})

add_executable(CPSL_compiler ${CPSL_compiler_srcs})
target_link_libraries(CPSL_compiler ${BISON_LIBRARIES})
target_include_directories(CPSL_compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
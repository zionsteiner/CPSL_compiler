//
// Created by zion on 3/11/20.
//

#ifndef CPSL_COMPILER_INCLUDES_H
#define CPSL_COMPILER_INCLUDES_H

#endif //CPSL_COMPILER_INCLUDES_H

// High-level misc
#include "classes/Block.h"
#include "classes/Body.h"
#include "classes/Param.h"
#include "classes/Program.h"

// Callable
#include "classes/Callable/Callable.h"
#include "classes/Callable/Function.h"
#include "classes/Callable/Procedure.h"

// Const
#include "classes/Const/ConstAssign.h"
#include "classes/Const/ConstDecl.h"

// Expr
#include "classes/Expr/Expr.h"
#include "classes/Ident.h"
#include "classes/ProcCall.h"

// * ConstExpr
#include "classes/ConstExpr/ConstExpr.h"
#include "classes/ConstExpr/BoolConstExpr.h"
#include "classes/ConstExpr/ChrConstExpr.h"
#include "classes/ConstExpr/IntConstExpr.h"
#include "classes/ConstExpr/StrConstExpr.h"

// * LValue
#include "classes/LValue/DotExt.h"
#include "classes/LValue/Ext.h"
#include "classes/LValue/IndexExt.h"
#include "classes/LValue/Lvalue.h"

// * OpExpr
#include "classes/OpExpr/OpExpr.h"

// ** BinOpExpr
#include "classes/OpExpr/BinOpExpr/BinOpExpr.h"

// *** ArithBinOpExpr
#include "classes/OpExpr/BinOpExpr/ArithBinOpExpr/ArithBinOpExpr.h"
#include "classes/OpExpr/BinOpExpr/ArithBinOpExpr/Add.h"
#include "classes/OpExpr/BinOpExpr/ArithBinOpExpr/Div.h"
#include "classes/OpExpr/BinOpExpr/ArithBinOpExpr/Mod.h"
#include "classes/OpExpr/BinOpExpr/ArithBinOpExpr/Mult.h"
#include "classes/OpExpr/BinOpExpr/ArithBinOpExpr/Sub.h"

// *** BoolBinOpExpr
#include "classes/OpExpr/BinOpExpr/BoolBinOpExpr/BoolBinOpExpr.h"
#include "classes/OpExpr/BinOpExpr/BoolBinOpExpr/Amp.h"
#include "classes/OpExpr/BinOpExpr/BoolBinOpExpr/Bar.h"

// *** CmprBinOpExpr
#include "classes/OpExpr/BinOpExpr/CmprBinOpExpr/CmprBinOpExpr.h"
#include "classes/OpExpr/BinOpExpr/CmprBinOpExpr/EQ.h"
#include "classes/OpExpr/BinOpExpr/CmprBinOpExpr/GEQ.h"
#include "classes/OpExpr/BinOpExpr/CmprBinOpExpr/GT.h"
#include "classes/OpExpr/BinOpExpr/CmprBinOpExpr/LEQ.h"
#include "classes/OpExpr/BinOpExpr/CmprBinOpExpr/LT.h"
#include "classes/OpExpr/BinOpExpr/CmprBinOpExpr/NEQ.h"

// ** UnaryOpExpr
#include "classes/OpExpr/UnaryOpExpr/Not.h"
#include "classes/OpExpr/UnaryOpExpr/UnaryOpExpr.h"
#include "classes/OpExpr/UnaryOpExpr/UnaryMinus.h"

// *** Intrinsic functions
#include "classes/OpExpr/UnaryOpExpr/IntrinsicFunc/ChrFunc.h"
#include "classes/OpExpr/UnaryOpExpr/IntrinsicFunc/OrdFunc.h"
#include "classes/OpExpr/UnaryOpExpr/IntrinsicFunc/PredFunc.h"
#include "classes/OpExpr/UnaryOpExpr/IntrinsicFunc/SuccFunc.h"

// Stmt
#include "classes/Stmt/Stmt.h"
#include "classes/Stmt/AssnStmt.h"
#include "classes/Stmt/IfStmt.h"
#include "classes/Stmt/ElseIfStmt.h"
#include "classes/Stmt/ElseStmt.h"
#include "classes/Stmt/ForStmt.h"
#include "classes/Stmt/ReadStmt.h"
#include "classes/Stmt/RepeatStmt.h"
#include "classes/Stmt/ReturnStmt.h"
#include "classes/Stmt/StopStmt.h"
#include "classes/Stmt/WhileStmt.h"
#include "classes/Stmt/WriteStmt.h"

// Type
#include "classes/Type/Type.h"
#include "classes/Type/ArrayType.h"
#include "classes/Type/RecordType.h"
#include "classes/Type/SimpleType.h"
#include "classes/Type/TypeAssign.h"
#include "classes/Type/TypeDecl.h"


// * Primitive types
#include "classes/Type/Primitive/Primitive.h"
#include "classes/Type/Primitive/ChrType.h"
#include "classes/Type/Primitive/IntType.h"
#include "classes/Type/Primitive/StrType.h"

// Var
#include "classes/Var/VarAssign.h"
#include "classes/Var/VarDecl.h"
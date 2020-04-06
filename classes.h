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
#include "classes/Expr/Ident.h"

// * ConstExpr
#include "classes/Expr/ConstExpr/ConstExpr.h"
#include "classes/Expr/ConstExpr/BoolConstExpr.h"
#include "classes/Expr/ConstExpr/ChrConstExpr.h"
#include "classes/Expr/ConstExpr/IntConstExpr.h"
#include "classes/Expr/ConstExpr/StrConstExpr.h"

// * LValue
#include "classes/Expr/LValue/DotExt.h"
#include "classes/Expr/LValue/Ext.h"
#include "classes/Expr/LValue/IndexExt.h"
#include "classes/Expr/LValue/LValue.h"

// * OpExpr
#include "classes/Expr/OpExpr/OpExpr.h"

// ** BinOpExpr
#include "classes/Expr/OpExpr/BinOpExpr/BinOpExpr.h"

// *** ArithBinOpExpr
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/ArithBinOpExpr.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Add.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Div.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Mod.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Mult.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Sub.h"

// *** BoolBinOpExpr
#include "classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/BoolBinOpExpr.h"
#include "classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Amp.h"
#include "classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Bar.h"

// *** CmprBinOpExpr
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/CmprBinOpExpr.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/Eq.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/Geq.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/Gt.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/Leq.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/Lt.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/Neq.h"

// ** UnaryOpExpr
#include "classes/Expr/OpExpr/UnaryOpExpr/Not.h"
#include "classes/Expr/OpExpr/UnaryOpExpr/UnaryOpExpr.h"
#include "classes/Expr/OpExpr/UnaryOpExpr/UnaryMinus.h"

// *** Intrinsic functions
#include "classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/ChrFunc.h"
#include "classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/OrdFunc.h"
#include "classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/PredFunc.h"
#include "classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/SuccFunc.h"

// Stmt
#include "classes/Stmt/Stmt.h"
#include "classes/Stmt/AssnStmt.h"
#include "classes/Stmt/IfStmt.h"
#include "classes/Stmt/ElseIfStmt.h"
#include "classes/Stmt/ElseStmt.h"
#include "classes/Stmt/ForStmt.h"
#include "classes/Stmt/ProcCall.h"
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
#include "classes/Type/Primitive.h"

// Var
#include "classes/Var/VarAssign.h"
#include "classes/Var/VarDecl.h"
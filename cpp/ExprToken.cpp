//
//  ExprToken.cpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-22.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#include "ExprToken.hpp"

ExprToken::ExprToken(int intVal, MathOperation mathOperation, bool hasSubExpr) {
    this->intVal = intVal;
    this->mathOperation = mathOperation;
    this->hasSubExpr = hasSubExpr;
}

ExprToken::ExprToken(MathOperation mathOperation) {
    this->mathOperation = mathOperation;
}

ExprToken::ExprToken(int intVal) {
    this->intVal = intVal;
}

//ExprToken::ExprToken(int intVal, MathOperation mathOperation) {
//    this->intVal = intVal;
//    this->mathOperation = mathOperation;
//}

ExprToken::ExprToken(int intVal, bool hasSubExpr) {
    this->intVal = intVal;
    this->hasSubExpr = hasSubExpr;
}

ExprToken::ExprToken(bool hasSubExpr) {
    this->hasSubExpr = hasSubExpr;
}

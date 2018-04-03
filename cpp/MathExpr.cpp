//
//  MathExpr.cpp
//  
//
//  Created by KyoKeun Park on 2018-03-20.
//

#include <iostream>
#include "MathExpr.hpp"
#include "AdditionExpr.hpp"
#include "SubtractionExpr.hpp"
#include "MultiplicationExpr.hpp"
#include "DivisionExpr.hpp"
#include "ModulusExpr.hpp"

MathExpr::MathExpr(MathOperation mathOperation) {
    this->mathOperation = mathOperation;
}

std::vector<ExprToken> MathExpr::produceExpression(SubExprLocation subExprLocation) {
    expression.push_back(ExprToken(this->mathOperation));
    if (isBounded && bound == 0)
        this->addZeroBoundTokens(subExprLocation);
    else {
        switch (subExprLocation) {
            case SubExprLocation::NEITHER :
                this->noSubExpressions();
                break;
            case SubExprLocation::LEFT :
                this->oneSubExpression(SubExprLocation::LEFT);
                break;
            case SubExprLocation::RIGHT :
                this->oneSubExpression(SubExprLocation::RIGHT);
                break;
            case SubExprLocation::BOTH :
                this->twoSubExpressions();
                break;
        }
    }
    return expression;
}

void MathExpr::setBound(int bound) {
    this->bound = bound;
    this->isBounded = true;
}

MathExpr *MathExpr::ExpressionFactory::createExpression(MathOperation expressionType,
                                                        int bound,
                                                        Level level) {
    MathExpr *expr;
    switch (expressionType) {
        case MathOperation::Addition :
            expr = new AdditionExpr(expressionType);
            break;
        case MathOperation::Subtraction :
            expr = new SubtractionExpr(expressionType);
            break;
        case MathOperation::Multiplication :
            expr = new MultiplicationExpr(expressionType);
            break;
        case MathOperation::Division :
            expr = new DivisionExpr(expressionType);
            break;
        case MathOperation::Modulus :
            expr = new ModulusExpr(expressionType);
            break;
        default:
            expr = nullptr;
            break;
    }
    if (expr != nullptr) {
        if (bound != -999) {
            expr->bound = bound;
        }
        expr->setMax(level);
    }
    // Temporary
    return expr;
}

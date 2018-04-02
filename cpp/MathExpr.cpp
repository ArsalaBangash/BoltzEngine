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

MathExpr::MathExpr(MathOperation mathOperation)
{
    this->mathOperation = mathOperation;
}

std::vector<ExprToken> MathExpr::produceExpression(SubExprLocation subExprLocation)
{
    expression.push_back(ExprToken(this->mathOperation));
    if (isBounded && bound == 0)
        this->addZeroBoundTokens(subExprLocation);
    else
    {
        switch(subExprLocation)
        {
            case SubExprLocation::NEITHER : this->noSubExpressions();
            case SubExprLocation::LEFT : this->oneSubExpression(SubExprLocation::LEFT);
            case SubExprLocation::RIGHT : this->oneSubExpression(SubExprLocation::RIGHT);
            case SubExprLocation::BOTH : this->twoSubExpressions();
        }
    }
    return expression;
}

void MathExpr::setBound(int bound)
{
    this->bound = bound;
    this->isBounded = true;
}

MathExpr *MathExpr::ExpressionFactory::createExpression(MathOperation expressionType,
                                                       int bound,
                                                       Level level)
{
    switch (expressionType)
    {
        case MathOperation::Addition : return new AdditionExpr(expressionType);
        case MathOperation::Subtraction : return new SubtractionExpr(expressionType);
        case MathOperation::Multiplication : return new MultiplicationExpr(expressionType);
        case MathOperation::Division : std::cout << "Division" << std::endl;
        case MathOperation::Modulus : std::cout << "Modulus" << std::endl;
        default:
            break;
    }
    // Temporary
    return new AdditionExpr(expressionType);
}

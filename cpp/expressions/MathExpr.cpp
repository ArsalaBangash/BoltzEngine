//
//  MathExpr.cpp
//  
//
//  Created by KyoKeun Park on 2018-03-20.
//

#include <iostream>
#include "MathExpr.hpp"

MathExpr::MathExpr(MathOperation mathOperation)
{
    this->mathOperation = mathOperation;
}

std::vector<ExprToken> MathExpr::produceExpression(SubExprLocation subExprLocation)
{
    expression.insert(expression.end(), ExprToken::ExprToken(this->mathOperation));
    if (isBounded && bound == 0)
        this->addZeroBoundTokens(subExprLocation);
    else
    {
        switch(subExprLocation)
        {
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

void MathExpr::setBound(int bound)
{
    this->bound = bound;
    this->isBounded = true;
}

MathExpr MathExpr::ExpressionFactory::createExpression(MathOperation expressionType,
                                                       int bound,
                                                       Level level)
{
    MathExpr *mathExpr;
    switch (expressionType)
    {
        case MathOperation::Addition :
            //mathExpr = AdditionExpr(expressionType);
            std::cout << "Addition" << std::endl;
            break;
        case MathOperation::Subtraction :
            std::cout << "Subtraction" << std::endl;
            break;
        case MathOperation::Multiplication :
            std::cout << "Multiplication" << std::endl;
            break;
        case MathOperation::Division :
            std::cout << "Division" << std::endl;
            break;
        case MathOperation::Modulus :
            std::cout << "Modulus" << std::endl;
            break;
        default:
            break;
    }
    return *mathExpr;
}

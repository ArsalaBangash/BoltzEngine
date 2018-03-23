//
//  MultiplicationExpr.cpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-22.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#include "MultiplicationExpr.hpp"
#include "EngineUtils.hpp"

void MultiplcationExpr::setMax(Level level)
{
    switch (level)
    {
        case Level::Basic : MAX = 5;
        case Level::Normal : MAX = 9;
        case Level::Advanced : MAX = 12;
    }
}

void MultiplcationExpr::addZeroBoundTokens(SubExprLocation subExprLocation)
{
    int operand1 = generatePositiveRandom(MAX);
    int operand2 = 0;
    
    switch (subExprLocation)
    {
        case SubExprLocation::NEITHER :
            expression.insert(expression.end(), ExprToken(operand1));
            expression.insert(expression.end(), ExprToken(operand2));
        case SubExprLocation::BOTH :
            expression.insert(expression.end(), ExprToken(operand1, true));
            expression.insert(expression.end(), ExprToken(operand2, true));
        case SubExprLocation::LEFT :
            expression.insert(expression.end(), ExprToken(operand1, true));
            expression.insert(expression.end(), ExprToken(operand2, true));
        case SubExprLocation::RIGHT :
            expression.insert(expression.end(), ExprToken(operand1));
            expression.insert(expression.end(), ExprToken(operand2, true));
    }
}

std::vector<ExprToken> MultiplcationExpr::produceExpression(SubExprLocation subExprLocation)
{
    if (this->isBounded)
    {
    }
}

//
// Created by KyoKeun Park on 2018-04-02.
//

#include "ModulusExpr.hpp"
#include "EngineUtils.hpp"

void ModulusExpr::setMax(Level level) {
    switch (level) {
        case Level::Basic :
            MIN = 1;
            MAX = 3;
            break;
        case Level::Normal :
            MIN = 2;
            MAX = 6;
            break;
        case Level::Advanced :
            MIN = 2;
            MAX = 10;
            break;
    }
}

void ModulusExpr::addZeroBoundTokens(SubExprLocation subExprLocation) {
    int constant = generatePositiveRandom(MIN, MAX);
    int divisor = generatePositiveRandom(MIN, MAX);
    switch (subExprLocation) {
        case SubExprLocation::NEITHER :
            expression.push_back(ExprToken(constant * divisor));
            expression.push_back(ExprToken(divisor));
            break;
        case SubExprLocation::BOTH :
            expression.push_back(ExprToken(constant * divisor, true));
            expression.push_back(ExprToken(divisor, true));
            break;
        case SubExprLocation::LEFT :
            expression.push_back(ExprToken(constant * divisor, true));
            expression.push_back(ExprToken(divisor));
            break;
        case SubExprLocation::RIGHT :
            expression.push_back(ExprToken(constant * divisor));
            expression.push_back(ExprToken(divisor, true));
            break;
    }
}

void ModulusExpr::noSubExpressions() {
    if (this->isBounded) {
        int divisor = generatePositiveRandom(bound + 1, MAX);
        int dividend = (divisor * generatePositiveRandom(MAX)) + bound;
        expression.push_back(ExprToken(dividend));
        expression.push_back(ExprToken(divisor));
    } else {
        int divisor = generatePositiveRandom(MIN, MAX);
        int dividend = generatePositiveRandom(MIN, MAX) + divisor;
        expression.push_back(ExprToken(dividend));
        expression.push_back(ExprToken(divisor));
    }
}

void ModulusExpr::twoSubExpressions() {
    int divisor, dividend;
    if (this->isBounded) {
        divisor = generatePositiveRandom(bound + 1, MAX);
        dividend = (divisor * generatePositiveRandom(MAX)) + bound;
    } else {
        divisor = generatePositiveRandom(MIN, MAX);
        dividend = generatePositiveRandom(MIN, MAX) + divisor;
    }
    expression.push_back(ExprToken(dividend, true));
    expression.push_back(ExprToken(divisor, true));
}

void ModulusExpr::oneSubExpression(SubExprLocation subExprLocation) {
    int divisor, dividend;
    if (this->isBounded) {
        divisor = generatePositiveRandom(bound, MAX);
        dividend = (divisor * generatePositiveRandom(MAX)) + bound;
    } else {
        divisor = generatePositiveRandom(MIN, MAX);
        dividend = generatePositiveRandom(MIN, MAX) + divisor;
    }
    switch (subExprLocation) {
        case SubExprLocation::LEFT :
            expression.push_back(ExprToken(dividend, true));
            expression.push_back(ExprToken(divisor));
            break;
        case SubExprLocation::RIGHT :
            expression.push_back(ExprToken(dividend));
            expression.push_back(ExprToken(divisor, true));
            break;
    }
}

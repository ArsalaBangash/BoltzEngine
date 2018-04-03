//
//  AdditionExpr.cpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-22.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#include "AdditionExpr.hpp"
#include "EngineUtils.hpp"

void AdditionExpr::setMax(Level level) {
    switch (level) {
        case Level::Basic:
            this->MIN = 1;
            this->MAX = 10;
            break;
        case Level::Normal:
            this->MIN = 5;
            this->MAX = 20;
            break;
        case Level::Advanced:
            this->MIN = 20;
            this->MAX = 100;
            break;
    }
}

void AdditionExpr::addZeroBoundTokens(SubExprLocation subExprLocation) {
    switch (subExprLocation) {
        case SubExprLocation::NEITHER :
            this->expression.insert(this->expression.end(), ExprToken(0));
            this->expression.insert(this->expression.end(), ExprToken(0));
            break;
        case SubExprLocation::BOTH :
            this->expression.insert(this->expression.end(), ExprToken(0, true));
            this->expression.insert(this->expression.end(), ExprToken(0, true));
            break;
        case SubExprLocation::LEFT :
            this->expression.insert(this->expression.end(), ExprToken(0, true));
            this->expression.insert(this->expression.end(), ExprToken(0));
            break;
        case SubExprLocation::RIGHT :
            this->expression.insert(this->expression.end(), ExprToken(0));
            this->expression.insert(this->expression.end(), ExprToken(0, true));
            break;
    }
}

void AdditionExpr::noSubExpressions() {
    if (this->isBounded) {
        int boundedRandom = generatePositiveRandom(MIN, bound);
        expression.insert(expression.end(), ExprToken(boundedRandom));
        expression.insert(expression.end(), ExprToken(bound - boundedRandom));
    } else {
        expression.insert(expression.end(), ExprToken(generatePositiveRandom(MIN, MAX)));
        expression.insert(expression.end(), ExprToken(generatePositiveRandom(MIN, MAX)));
    }
}

void AdditionExpr::twoSubExpressions() {
    if (this->isBounded) {
        int boundedRandom = generatePositiveRandom(MIN, bound);
        int boundedRandomComplement = bound - boundedRandom;
        expression.insert(expression.end(), ExprToken(boundedRandom, true));
        expression.insert(expression.end(), ExprToken(boundedRandomComplement, true));
    } else {
        expression.insert(expression.end(), ExprToken(true));
        expression.insert(expression.end(), ExprToken(true));
    }
}

void AdditionExpr::oneSubExpression(SubExprLocation subExprLocation) {
    int boundedRandom, boundedRandomComplement;
    switch (subExprLocation) {
        case SubExprLocation::LEFT :
            if (this->isBounded) {
                boundedRandom = generatePositiveRandom(MIN, bound);
                boundedRandomComplement = bound - boundedRandom;
                expression.insert(expression.end(), ExprToken(boundedRandom, true));
                expression.insert(expression.end(), ExprToken(boundedRandomComplement));
            } else {
                expression.insert(expression.end(), ExprToken(true));
                expression.insert(expression.end(), ExprToken(generatePositiveRandom(MIN, MAX)));
            }
            break;
        case SubExprLocation::RIGHT :
            if (this->isBounded) {
                boundedRandom = generatePositiveRandom(MIN, bound);
                boundedRandomComplement = bound - boundedRandom;
                expression.insert(expression.end(), ExprToken(boundedRandom));
                expression.insert(expression.end(), ExprToken(boundedRandomComplement, true));
            } else {
                expression.insert(expression.end(), ExprToken(generatePositiveRandom(MIN, MAX)));
                expression.insert(expression.end(), ExprToken(true));
            }
            break;
        default: // This is to mute the warning
            break;
    }
}

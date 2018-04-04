//
//  AdditionExpr.cpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-22.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#include <iostream>
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
            this->expression.emplace_back(ExprToken(0));
            this->expression.emplace_back(ExprToken(0));
            break;
        case SubExprLocation::BOTH :
            this->expression.emplace_back(ExprToken(0, true));
            this->expression.emplace_back(ExprToken(0, true));
            break;
        case SubExprLocation::LEFT :
            this->expression.emplace_back(ExprToken(0, true));
            this->expression.emplace_back(ExprToken(0));
            break;
        case SubExprLocation::RIGHT :
            this->expression.emplace_back(ExprToken(0));
            this->expression.emplace_back(ExprToken(0, true));
            break;
    }
}

void AdditionExpr::noSubExpressions() {
    if (this->isBounded) {
        int boundedRandom = generatePositiveRandom(MIN, bound);
        expression.emplace_back(ExprToken(boundedRandom));
        expression.emplace_back(ExprToken(bound - boundedRandom));
    } else {
        expression.emplace_back(ExprToken(generatePositiveRandom(MIN, MAX)));
        expression.emplace_back(ExprToken(generatePositiveRandom(MIN, MAX)));
    }
}

void AdditionExpr::twoSubExpressions() {
    if (this->isBounded) {
        int boundedRandom = generatePositiveRandom(MIN, bound);
        int boundedRandomComplement = bound - boundedRandom;
        expression.emplace_back(ExprToken(boundedRandom, true));
        expression.emplace_back(ExprToken(boundedRandomComplement, true));
    } else {
        expression.emplace_back(ExprToken(true));
        expression.emplace_back(ExprToken(true));
    }
}

void AdditionExpr::oneSubExpression(SubExprLocation subExprLocation) {
    int boundedRandom, boundedRandomComplement;
    switch (subExprLocation) {
        case SubExprLocation::LEFT :
            if (this->isBounded) {
                boundedRandom = generatePositiveRandom(MIN, bound);
                boundedRandomComplement = bound - boundedRandom;
                expression.emplace_back(ExprToken(boundedRandom, true));
                expression.emplace_back(ExprToken(boundedRandomComplement));
            } else {
                expression.emplace_back(ExprToken(true));
                expression.emplace_back(ExprToken(generatePositiveRandom(MIN, MAX)));
            }
            break;
        case SubExprLocation::RIGHT :
            if (this->isBounded) {
                boundedRandom = generatePositiveRandom(MIN, bound);
                boundedRandomComplement = bound - boundedRandom;
                expression.emplace_back(ExprToken(boundedRandom));
                expression.emplace_back(ExprToken(boundedRandomComplement, true));
            } else {
                expression.emplace_back(ExprToken(generatePositiveRandom(MIN, MAX)));
                expression.emplace_back(ExprToken(true));
            }
            break;
        case NEITHER:
            break;
        case BOTH:
            break;
    }
}

//
//  SubtractionExpr.cpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-22.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#include "SubtractionExpr.hpp"
#include "EngineUtils.hpp"

void SubtractionExpr::setMax(Level level) {
    switch (level) {
        case Level::Basic :
            MIN = 1;
            MAX = 10;
        case Level::Normal :
            MIN = 5;
            MAX = 10;
        case Level::Advanced :
            MIN = 20;
            MAX = 100;
    }
}

void SubtractionExpr::addZeroBoundTokens(SubExprLocation subExprLocation) {
    switch (subExprLocation) {
        case SubExprLocation::NEITHER :
            expression.insert(expression.end(), ExprToken(0));
            expression.insert(expression.end(), ExprToken(0));
            break;
        case SubExprLocation::BOTH :
            expression.insert(expression.end(), ExprToken(0, true));
            expression.insert(expression.end(), ExprToken(0, true));
            break;
        case SubExprLocation::LEFT :
            expression.insert(expression.end(), ExprToken(0, true));
            expression.insert(expression.end(), ExprToken(0));
            break;
        case SubExprLocation::RIGHT :
            expression.insert(expression.end(), ExprToken(0));
            expression.insert(expression.end(), ExprToken(0, true));
            break;
    }
}

void SubtractionExpr::noSubExpressions() {
    if (this->isBounded) {
        int boundedRandom = generatePositiveRandom(MIN, bound);
        expression.insert(expression.end(), ExprToken(boundedRandom));
        expression.insert(expression.end(), ExprToken(bound - boundedRandom));
    } else {
        expression.insert(expression.end(), ExprToken(generatePositiveRandom(MIN, MAX)));
        expression.insert(expression.end(), ExprToken(generatePositiveRandom(MIN, MAX)));
    }
}

void SubtractionExpr::twoSubExpressions() {
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

void SubtractionExpr::oneSubExpression(SubExprLocation subExprLocation) {
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
                expression.insert(expression.end(), ExprToken(boundedRandomComplement));
            } else {
                expression.insert(expression.end(), ExprToken(generatePositiveRandom(MIN, MAX)));
                expression.insert(expression.end(), ExprToken(true));
            }
            break;
        default:
            break;
    }
}

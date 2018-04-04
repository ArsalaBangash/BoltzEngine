//
//  MultiplicationExpr.cpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-22.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#include <iostream>
#include "MultiplicationExpr.hpp"
#include "EngineUtils.hpp"
#include <cmath>


void MultiplicationExpr::setMax(Level level) {
    switch (level) {
        case Level::Basic :
            MAX = 5;
            break;
        case Level::Normal :
            MAX = 9;
            break;
        case Level::Advanced :
            MAX = 12;
            break;
    }
}

void MultiplicationExpr::addZeroBoundTokens(SubExprLocation subExprLocation) {
    int operand1 = generatePositiveRandom(MAX);
    int operand2 = 0;

    switch (subExprLocation) {
        case SubExprLocation::NEITHER :
            expression.emplace_back(operand1);
            expression.emplace_back(ExprToken(operand2));
            break;
        case SubExprLocation::BOTH :
            expression.emplace_back(ExprToken(operand2, true));
            expression.emplace_back(ExprToken(operand2, true));
            break;
        case SubExprLocation::LEFT :
            expression.emplace_back(ExprToken(operand1, true));
            expression.emplace_back(ExprToken(operand2));
            break;
        case SubExprLocation::RIGHT :
            expression.emplace_back(ExprToken(operand1));
            expression.emplace_back(ExprToken(operand2, true));
            break;
    }
}

std::vector<ExprToken> MultiplicationExpr::produceExpression(SubExprLocation subExprLocation) {
    if (this->isBounded) {
        auto bound = static_cast<int>(fabs(this->bound));
        std::vector<int> allNumbers(static_cast<unsigned long>(bound));
        std::vector<int> filteredNumbers;

        // Fill allNumbers with the numbers between 1 and bound
        std::iota(begin(allNumbers), end(allNumbers), 1);
        // Only copy the numbers to filteredNumbers if the number is divisible by bound
//        std::copy_if(begin(allNumbers), end(allNumbers), begin(filteredNumbers),
//                     [bound](int i) { return bound % i; });
        for (int i = 1; i <= bound; i++) {
            if (bound % i == 0)
                filteredNumbers.emplace_back(i);
        }

        this->multiples = std::vector<std::vector<int> >(filteredNumbers.size());
        // Populate multiple with all possible pairs of numbers that makes number bound
        for (int i = 0; i < filteredNumbers.size(); i++) {
            if (this->bound < 0) {
                if (random(0, 1) > 0.5) {
                    this->multiples[i].emplace_back(filteredNumbers[i] * -1);
                    this->multiples[i].emplace_back(bound / filteredNumbers[i]);
                } else {
                    this->multiples[i].emplace_back(filteredNumbers[i]);
                    this->multiples[i].emplace_back((bound / filteredNumbers[i]) * -1);
                }
            } else {
                this->multiples[i].emplace_back(filteredNumbers[i]);
                this->multiples[i].emplace_back(bound / filteredNumbers[i]);
            }
        }
    }
    return MathExpr::produceExpression(subExprLocation);
}

void MultiplicationExpr::noSubExpressions() {
    if (this->isBounded) {
        std::vector<int> boundMultiples = multiples[random_index(multiples.size())];
        expression.emplace_back(ExprToken(boundMultiples[0]));
        expression.emplace_back(ExprToken(boundMultiples[1]));
    } else {
        expression.emplace_back(ExprToken(generatePositiveRandom(MAX) + 1));
        expression.emplace_back(ExprToken(generatePositiveRandom(MAX) + 1));
    }
}

void MultiplicationExpr::twoSubExpressions() {
    if (this->isBounded) {
        std::vector<int> boundMultiples = multiples[random_index(multiples.size())];
        expression.emplace_back(ExprToken(boundMultiples[0], true));
        expression.emplace_back(ExprToken(boundMultiples[1], true));
    } else {
        expression.emplace_back(ExprToken(generatePositiveRandom(MAX) + 1, true));
        expression.emplace_back(ExprToken(generatePositiveRandom(MAX) + 1, true));
    }
}

void MultiplicationExpr::oneSubExpression(SubExprLocation subExprLocation) {
    switch (subExprLocation) {
        case SubExprLocation::LEFT :
            if (this->isBounded) {
                std::vector<int> boundMultiples = multiples[random_index(multiples.size())];
                expression.emplace_back(ExprToken(boundMultiples[0], true));
                expression.emplace_back(ExprToken(boundMultiples[1]));
            } else {
                expression.emplace_back(ExprToken(generatePositiveRandom(MAX) + 1, true));
                expression.emplace_back(ExprToken(generatePositiveRandom(MAX) + 1));
            }
            break;
        case SubExprLocation::RIGHT :
            if (this->isBounded) {
                std::vector<int> boundMultiples = multiples[random_index(multiples.size())];
                expression.emplace_back(ExprToken(boundMultiples[0]));
                expression.emplace_back(ExprToken(boundMultiples[1], true));
            } else {
                expression.emplace_back(ExprToken(generatePositiveRandom(MAX) + 1));
                expression.emplace_back(ExprToken(generatePositiveRandom(MAX) + 1, true));
            }
            break;
        default:
            std::cout << "Should not happen\n";
    }
}

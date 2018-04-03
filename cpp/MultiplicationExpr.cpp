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


void MultiplicationExpr::setMax(Level level) {
    switch (level) {
        case Level::Basic :
            MAX = 5;
        case Level::Normal :
            MAX = 9;
        case Level::Advanced :
            MAX = 12;
    }
}

void MultiplicationExpr::addZeroBoundTokens(SubExprLocation subExprLocation) {
    int operand1 = generatePositiveRandom(MAX);
    int operand2 = 0;

    switch (subExprLocation) {
        case SubExprLocation::NEITHER :
            expression.push_back(ExprToken(operand1));
            expression.push_back(ExprToken(operand2));
            break;
        case SubExprLocation::BOTH :
            expression.push_back(ExprToken(operand2, true));
            expression.push_back(ExprToken(operand2, true));
            break;
        case SubExprLocation::LEFT :
            expression.push_back(ExprToken(operand1, true));
            expression.push_back(ExprToken(operand2));
            break;
        case SubExprLocation::RIGHT :
            expression.push_back(ExprToken(operand1));
            expression.push_back(ExprToken(operand2, true));
            break;
    }
}

std::vector<ExprToken> MultiplicationExpr::produceExpression(SubExprLocation subExprLocation) {
    if (this->isBounded) {
        int bound = this->bound;
        std::vector<int> allNumbers(bound);
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

        this->multiples = std::vector< std::vector<int> >(filteredNumbers.size());
        // Populate multiple with all possible pairs of numbers that makes number bound
        for (int i = 0; i < filteredNumbers.size(); i++) {
//            this->multiples[i][0] = filteredNumbers[i];
            this->multiples[i].emplace_back(filteredNumbers[i]);
//            this->multiples[i][1] = bound / filteredNumbers[i];
            this->multiples[i].emplace_back(bound / filteredNumbers[i]);
        }
    }
    return MathExpr::produceExpression(subExprLocation);
}

void MultiplicationExpr::noSubExpressions() {
    if (this->isBounded) {
        std::vector<int> boundMultiples = multiples[random_index(multiples.size())];
        expression.push_back(ExprToken(boundMultiples[0]));
        expression.push_back(ExprToken(boundMultiples[1]));
    } else {
        expression.push_back(ExprToken(generatePositiveRandom(MAX) + 1));
        expression.push_back(ExprToken(generatePositiveRandom(MAX) + 1));
    }
}

void MultiplicationExpr::twoSubExpressions() {
    if (this->isBounded) {
        std::vector<int> boundMultiples = multiples[random_index(multiples.size())];
        expression.push_back(ExprToken(boundMultiples[0], true));
        expression.push_back(ExprToken(boundMultiples[1], true));
    } else {
        expression.push_back(ExprToken(generatePositiveRandom(MAX) + 1, true));
        expression.push_back(ExprToken(generatePositiveRandom(MAX) + 1, true));
    }
}

void MultiplicationExpr::oneSubExpression(SubExprLocation subExprLocation) {
    switch (subExprLocation) {
        case SubExprLocation::LEFT :
            if (this->isBounded) {
                std::vector<int> boundMultiples = multiples[random_index(multiples.size())];
                expression.push_back(ExprToken(boundMultiples[0], true));
                expression.push_back(ExprToken(boundMultiples[1]));
            } else {
                expression.push_back(ExprToken(generatePositiveRandom(MAX) + 1, true));
                expression.push_back(ExprToken(generatePositiveRandom(MAX) + 1));
            }
            break;
        case SubExprLocation::RIGHT :
            if (this->isBounded) {
                std::vector<int> boundMultiples = multiples[random_index(multiples.size())];
                expression.push_back(ExprToken(boundMultiples[0]));
                expression.push_back(ExprToken(boundMultiples[1], true));
            } else {
                expression.push_back(ExprToken(generatePositiveRandom(MAX) + 1));
                expression.push_back(ExprToken(generatePositiveRandom(MAX) + 1, true));
            }
            break;
        default:
            std::cout << "Should not happen\n";
    }
}

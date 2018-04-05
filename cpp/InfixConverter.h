//
// Created by Arsala Bangash on 2018-04-03.
//

#ifndef BOLTZENGINE_INFIXCONVERTER_H
#define BOLTZENGINE_INFIXCONVERTER_H


#include <string>
#include <stack>
#include <map>
#include "ExprToken.hpp"
#include "MathExpr.hpp"

class InfixConverter {

    std::map<MathOperation, std::string> opMap;


public:
    InfixConverter();

    void binaryOpToInfix(MathOperation, std::stack<std::string> *);

    std::string exprToInfix(std::vector<ExprToken>);

};


#endif //BOLTZENGINE_INFIXCONVERTER_H

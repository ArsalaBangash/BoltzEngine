//
// Created by Arsala Bangash on 2018-04-03.
//

#include <vector>
#include "InfixConverter.h"
#include <map>


InfixConverter::InfixConverter() {
    opMap[Addition] = "+";
    opMap[Subtraction] = "-";
    opMap[Division] = "/";
    opMap[Multiplication] = "*";
    opMap[Modulus] = "%";
}

std::string InfixConverter::exprToInfix(std::vector<ExprToken> expression) {

    auto *expressionStack = new std::stack<std::string>();

    for (int i = static_cast<int>(expression.size() - 1); i >= 0; i--) {
        if (expression[i].intVal == -999) {
            MathOperation currentOp = expression[i].mathOperation;
            binaryOpToInfix(currentOp, expressionStack);
        } else expressionStack->push(std::to_string(expression[i].intVal));
    }
    return expressionStack->top();
}

void InfixConverter::binaryOpToInfix(MathOperation binaryOp, std::stack<std::string> *exprStack) {
    std::string left = exprStack->top();
    exprStack->pop();
    std::string right = exprStack->top();
    exprStack->pop();
    std::string expr_string = "(";
    expr_string.append(left).append(" ").append(opMap.at(binaryOp)).append(" ").append(right).append(")");
    exprStack->push(expr_string);
}
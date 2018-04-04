//
// Created by KyoKeun Park on 2018-04-03.
//

#include <boost/algorithm/string.hpp>
#include "LatexConverter.hpp"

LatexConverter::LatexConverter() {
    opRepresentationMap.emplace(Addition, addLatex);
    opRepresentationMap.emplace(Subtraction, subLatex);
    opRepresentationMap.emplace(Multiplication, multLatex);
    opRepresentationMap.emplace(Modulus, modLatex);
    opRepresentationMap.emplace(Division, divLatex);
}

std::string LatexConverter::exprToLatex(std::vector<ExprToken>& expressions) {
    std::stack<std::string> expressionStack;
    std::reverse(begin(expressions), end(expressions)); // reverse the expressions list
    for (int i = 0; i < expressions.size(); i++) {
        if (expressions[i].mathOperation == Invalid) {
            MathOperation currentOp = expressions[i].mathOperation;
            expressionStack(opRepresentationMap[currentOp](expressionStack));
        }
    }
}

std::string LatexConverter::parenthesizeNegative(std::string number) {
    if (boost::starts_with(number, "-"))
        return std::string("(").append(number).append(")");
    else
        return number;
}
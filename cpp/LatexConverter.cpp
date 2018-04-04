//
// Created by KyoKeun Park on 2018-04-03.
//

#include <boost/algorithm/string.hpp>
#include "LatexConverter.hpp"
#include <vector>

LatexConverter::LatexConverter() {
    opRepresentationMap.emplace(Addition, addLatex);
    opRepresentationMap.emplace(Subtraction, subLatex);
    opRepresentationMap.emplace(Multiplication, multLatex);
    opRepresentationMap.emplace(Modulus, modLatex);
    opRepresentationMap.emplace(Division, divLatex);
}

std::string LatexConverter::exprToLatex(std::vector<ExprToken> &expressions) {
    std::stack<std::string> expressionStack;
    std::reverse(begin(expressions), end(expressions)); // reverse the expressions list
    for (auto &expression : expressions) {
        if (expression.mathOperation == Invalid) {
            MathOperation currentOp = expression.mathOperation;
            expressionStack.push(opRepresentationMap[currentOp](expressionStack));
        } else expressionStack.push(std::to_string(expression.intVal));
    }
    std::string latexExpr = getAndPop(expressionStack);
    if (boost::starts_with(latexExpr, "(") && boost::ends_with(latexExpr, ")"))
        return std::string("$$").append(latexExpr.substr(1, latexExpr.size() - 2)).append("$$");
    else return std::string("$$").append(latexExpr).append("$$");
}

std::string LatexConverter::factorToLatex(std::vector<int> &expandedParams) {
    std::string factorLatex("$$");
    if (expandedParams.at(1) == 1)
        factorLatex.append("x^{2}");
    else
        factorLatex.append(std::to_string(expandedParams[2])).append("x^2");

    if (expandedParams[1] > 0) factorLatex.append(" + ");
    if (expandedParams[1] != 0) factorLatex.append(std::to_string(expandedParams[1])).append("x");

    if (expandedParams[0] > 0) factorLatex.append(" + ");
    if (expandedParams[0] != 0) factorLatex.append(std::to_string(expandedParams[0]));

    return factorLatex;
}

std::string LatexConverter::parenthesizeNegative(std::string number) {
    if (boost::starts_with(number, "-"))
        return std::string("(").append(number).append(")");
    else
        return number;
}
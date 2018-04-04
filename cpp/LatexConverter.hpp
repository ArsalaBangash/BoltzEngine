//
// Created by KyoKeun Park on 2018-04-03.
//

#ifndef BOLTZENGINE_LATEXCONVERTER_HPP
#define BOLTZENGINE_LATEXCONVERTER_HPP

#include <map>
#include <stack>
#include <string>
#include <vector>
#include "Enums.h"
#include "ExprToken.hpp"
#include "EngineUtils.hpp"

class LatexConverter {

public:
    LatexConverter();
    std::string exprToLatex(std::vector<ExprToken>&);
    std::string factorToLatex(std::vector<int>);

private:
    std::map<MathOperation, std::string(*)(std::stack<std::string>)> opRepresentationMap;

    auto addLatex = [](std::stack<std::string> exprStack) {
        return std::string("(").append(getAndPop(exprStack)).append("+").append(parenthesizeNegative(getAndPop(exprStack))).append(")");
    };

    auto subLatex = [](std::stack<std::string> exprStack) {
        return std::string("(").append(getAndPop(exprStack)).append("-").append(parenthesizeNegative(getAndPop(exprStack))).append(")");
    };

    auto multLatex = [](std::stack<std::string> exprStack) {
        return std::string("(").append(getAndPop(exprStack)).append("\\times").append(parenthesizeNegative(getAndPop(exprStack))).append(")");
    };

    auto modLatex = [](std::stack<std::string> exprStack) {
        return std::string("(").append(getAndPop(exprStack)).append(" \\% ").append(parenthesizeNegative(getAndPop(exprStack))).append(")");
    };

    auto divLatex = [](std::stack<std::string> exprStack) {
        std::string dividend = getAndPop(exprStack);
        std::string divisor = getAndPop(exprStack);
        if (boost::starts_with(dividend, "\\frac") || boost::starts_with(divisor, "\\frac"))
            return std::string(dividend).append(" \\div ").append(divisor);
        else
            return std::string("\\frac{").append(dividend).append("}{").append(divisor).append("}");
    };

    std::string parenthesizeNegative(std::string);
};

#endif //BOLTZENGINE_LATEXCONVERTER_HPP

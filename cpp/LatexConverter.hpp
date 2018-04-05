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
    std::string exprToLatex(std::vector<ExprToken>);
    std::string factorToLatex(std::vector<int>&);

private:
    std::map<MathOperation, std::function<std::string(std::stack<std::string>*)>> opRepresentationMap;

    std::function<std::string(std::stack<std::string>*)> addLatex = [](std::stack<std::string> *exprStack) -> std::string  {
        return std::string("(").append(getAndPop(exprStack)).append("+").append(parenthesizeNegative(getAndPop(exprStack))).append(")");
    };

    std::function<std::string(std::stack<std::string>*)> subLatex = [](std::stack<std::string> *exprStack) -> std::string {
        return std::string("(").append(getAndPop(exprStack)).append("-").append(parenthesizeNegative(getAndPop(exprStack))).append(")");
    };

    std::function<std::string(std::stack<std::string>*)> multLatex = [](std::stack<std::string> *exprStack) -> std::string {
        return std::string("(").append(getAndPop(exprStack)).append("\\times").append(parenthesizeNegative(getAndPop(exprStack))).append(")");
    };

    std::function<std::string(std::stack<std::string>*)> modLatex = [](std::stack<std::string> *exprStack) -> std::string {
        return std::string("(").append(getAndPop(exprStack)).append(" \\% ").append(parenthesizeNegative(getAndPop(exprStack))).append(")");
    };

    std::function<std::string(std::stack<std::string>*)> divLatex = [](std::stack<std::string> *exprStack) -> std::string {
        std::string prefix = "\\frac";
        std::string dividend = getAndPop(exprStack);
        std::string divisor = getAndPop(exprStack);
        if (!divisor.compare(0, prefix.size(), prefix) ||
            !dividend.compare(0, prefix.size(), prefix))
            return std::string(dividend).append(" \\div ").append(divisor);
        else
            return std::string("\\frac{").append(dividend).append("}{").append(divisor).append("}");
    };

    static std::string parenthesizeNegative(std::string);
};

#endif //BOLTZENGINE_LATEXCONVERTER_HPP

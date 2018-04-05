/*
 **************************************************************
 *         C++ Mathematical Expression Toolkit Library        *
 *                                                            *
 * Simple Example 1                                           *
 * Author: Arash Partow (1999-2018)                           *
 * URL: http://www.partow.net/programming/exprtk/index.html   *
 *                                                            *
 * Copyright notice:                                          *
 * Free use of the Mathematical Expression Toolkit Library is *
 * permitted under the guidelines and in accordance with the  *
 * most current version of the MIT License.                   *
 * http://www.opensource.org/licenses/MIT                     *
 *                                                            *
 **************************************************************
*/


#include <cstdio>
#include <string>

#include "exprtk.hpp"
#include <iostream>
#include <vector>
#include "ExprGenerator.hpp"
#include "AdditionExpr.hpp"
#include "SubtractionExpr.hpp"
#include "EngineUtils.hpp"
#include "BinaryGenerator.hpp"
#include "FactorizationGenerator.hpp"
#include "InfixConverter.h"
#include "LatexConverter.hpp"

std::string genExpr() {
    std::vector<MathOperation> operations;
    operations.emplace_back(Addition);
    operations.emplace_back(Multiplication);
    operations.emplace_back(Division);
    auto *infixConverter = new InfixConverter;
    std::vector<ExprToken> exprTokens = ExprGenerator::generateExpression(operations, Normal);
    std::string expression_string = infixConverter->exprToInfix(exprTokens);
    return expression_string;
}


template<typename T>
void expression() {
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T> expression_t;
    typedef exprtk::parser<T> parser_t;


    std::string expression_string = genExpr();
    cout << expression_string << " =  ";

    expression_t expression;

    parser_t parser;
    parser.compile(expression_string, expression);

    T y = expression.value();
    cout << y << endl;
}

int main() {
    int runs = 100;
    for (int i = 0; i < runs; i++) {
        expression<double>();
    }
    return 0;
}
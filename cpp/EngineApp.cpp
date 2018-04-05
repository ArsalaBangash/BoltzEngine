//
// Created by Arsala Bangash on 2018-04-02.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include "EngineApp.h"
#include "Enums.h"
#include "InfixConverter.h"
#include "ExprGenerator.hpp"
#include "LatexConverter.hpp"
#include "exprtk.hpp"


template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

std::vector<MathOperation> mapInputOps(const std::string &inputOps) {
    std::vector<std::string> splitOps = split(inputOps, ' ');
    std::vector<MathOperation> operations;
    for (const auto &splitOp : splitOps) {
        if (splitOp == "Addition") {
            operations.emplace_back(Addition);
        } else if (splitOp == "Subtraction") {
            operations.emplace_back(Subtraction);
        } else if (splitOp == "Multiplication") {
            operations.emplace_back(Multiplication);
        } else if (splitOp == "Division") {
            operations.emplace_back(Division);
        } else {
            operations.emplace_back(Modulus);
        }
    }
    return operations;
}

ChallengeReps genExpression(std::string ops, Level level) {
    auto *infixConverter = new InfixConverter;
    auto *latexConverter = new LatexConverter;
    std::vector<MathOperation> operations = mapInputOps(ops);
    std::vector<ExprToken> exprTokens = ExprGenerator::generateExpression(operations, level);
    std::string infixRepr = infixConverter->exprToInfix(exprTokens);
    std::string latexRepr = latexConverter->exprToLatex(exprTokens);
    ChallengeReps reps = ChallengeReps{};
    reps.infixRepr = infixRepr;
    reps.latexRepr = latexRepr;
    return reps;
}

template<typename T>
bool check(std::string expression, const std::string &userAnswer) {
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T> expression_t;
    typedef exprtk::parser<T> parser_t;

    expression_t expr;
    parser_t parser;
    expression.append(" = ").append(userAnswer);
    parser.compile(expression, expr);
    T y = expr.value();
    if (y == y) {
        return (bool) y;
    } else return false;
}

bool checkAnswer(const std::string &expression, const std::string &userAnswer) {
    return check<double>(expression, userAnswer);
}


void runApp() {
    std::string inputOps;
    std::cout << "Enter math operations separated by spaces: ";
    std::getline(std::cin, inputOps);
    ChallengeReps reps = genExpression(inputOps, Normal);
    std::cout << reps.infixRepr << std::endl;
    std::string answer;
    std::cout << "Enter your answer: ";
    std::getline(std::cin, answer);
    std::string answerCheck;
    if (checkAnswer(reps.infixRepr, answer)) {
        answerCheck = "correct";
    } else answerCheck = "wrong";
    std::cout << "Your answer was " << answerCheck << std::endl;
}

//int main() {
//    while (true) {
//        runApp();
//    }
//}

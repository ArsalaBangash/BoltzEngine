#include <iostream>
#include <vector>
#include "AdditionExpr.hpp"
#include "BinaryGenerator.hpp"
#include "EngineUtils.hpp"
#include "ExprGenerator.hpp"
#include "FactorizationGenerator.hpp"
#include "HexGenerator.hpp"
#include "InfixConverter.h"
#include "LatexConverter.hpp"
#include "SubtractionExpr.hpp"
#include "exprtk.hpp"

using namespace std;

#include <ctime>

double testTime(long numExpressions,
                const std::vector<MathOperation> &operations) {
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    while (numExpressions > 0) {
        std::vector<ExprToken> exprTokens =
                ExprGenerator::generateExpression(operations, Normal);
        numExpressions--;
    }
    clock::time_point end = clock::now();
    clock::duration execution_time = end - start;
    return execution_time.count();
}

void testInfix() {
    std::vector<MathOperation> operations;
    operations.emplace_back(Addition);
    operations.emplace_back(Subtraction);
    operations.emplace_back(Multiplication);
    operations.emplace_back(Division);

    InfixConverter *infixConverter = new InfixConverter;
    std::vector<ExprToken> exprTokens =
            ExprGenerator::generateExpression(operations, Normal);
    std::string expression_string = infixConverter->exprToInfix(exprTokens);
    cout << expression_string << endl;
}

void benchmark() {
    std::vector<MathOperation> operations;
    operations.emplace_back(Addition);
    operations.emplace_back(Multiplication);
    operations.emplace_back(Division);

    long numExpressions = 100000;
    long acc = 0L;
    int i = 10;
    while (i > 0) {
        acc += testTime(numExpressions, operations) / 1000000;
        i--;
    }
    acc = acc / 10;
    cout << "time: " << acc << endl;
}

void testHex() {
    HexChallenge hc = generateHexQuestion(Advanced);
    cout << hc.decimal << "\t" << hc.hex << endl;
}

void testLatex() {
    std::vector<MathOperation> operations;
    operations.emplace_back(Addition);
    operations.emplace_back(Multiplication);
    operations.emplace_back(Division);
    auto *lc = new LatexConverter();
    auto *ic = new InfixConverter();
    std::vector<ExprToken> exprTokens =
            ExprGenerator::generateExpression(operations, Basic);

    std::string icExprOutput = ic->exprToInfix(exprTokens);
    std::string lcExprOutput = lc->exprToLatex(exprTokens);
    cout << "\n" << lcExprOutput << endl;
    cout << icExprOutput << endl;
}

int main() {
    /*
     * Call the function you woiuld like to test here
     */
    return 0;
}

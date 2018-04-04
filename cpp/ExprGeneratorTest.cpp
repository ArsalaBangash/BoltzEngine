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
#include "HexGenerator.hpp"

using namespace std;

#include <ctime>

double testTime(long numExpressions, const std::vector<MathOperation> &operations) {
//    InfixConverter *infixConverter = new InfixConverter;
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    while (numExpressions > 0) {
        std::vector<ExprToken> exprTokens = ExprGenerator::generateExpression(operations, Normal);
//        cout << infixConverter->exprToInfix(exprTokens) << endl;
        numExpressions--;
    }
    clock::time_point end = clock::now();
    clock::duration execution_time = end - start;
    return execution_time.count();
}

int main() {

    std::vector<MathOperation> operations;
    operations.emplace_back(Addition);
//    operations.emplace_back(Addition);
//    operations.emplace_back(Addition);
    operations.emplace_back(Subtraction);
    operations.emplace_back(Multiplication);
    operations.emplace_back(Division);

    /*
    InfixConverter *infixConverter = new InfixConverter;

//    time_t start_s = clock();
//    // the code you wish to time goes here
//
//    int i = 100000;
//    while (i > 0) {
//        std::vector<ExprToken> exprTokens = ExprGenerator::generateExpression(operations, Normal);
////        cout << infixConverter->exprToInfix(exprTokens) << endl;
//        i--;
//    }
//    time_t stop_s = clock();
//    cout << "time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;

    long numExpressions = 100000;
    long acc = 0L;
    int i = 5;
    while (i > 0) {
        acc += testTime(numExpressions, operations) / 1000000;
        i--;
    }
    acc = acc / 5;
    cout << "time: " << acc << endl;


//    BinaryChallenge *binary = BinaryChallenge::generateBinaryQuestion(Normal);
//
//    cout << binary->binary << " : " << binary->decimal << endl;
//
//    auto *fact = new FactorizationGenerator();
//    vector<int> int_list = fact->getExpandedParams("1+2-3");
     */

    auto *lc = new LatexConverter();
    auto *ic = new InfixConverter();
    std::vector<ExprToken> exprTokens = ExprGenerator::generateExpression(operations, Basic);

    for (int i = 0; i < exprTokens.size(); i++) {
        cout << ExprToken::exprString(exprTokens[i]) << endl;
    }

    std::string icExprOutput = ic->exprToInfix(exprTokens);
    std::string lcExprOutput = lc->exprToLatex(exprTokens);
    cout << "\n" << lcExprOutput << endl;
    cout << icExprOutput << endl;

    HexChallenge hc = generateHexQuestion(Advanced);
    cout << hc.decimal << "\t" << hc.hex << endl;

    cout << "exprToken generated successfully\n";

    return 0;
}



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

using namespace std;

#include <ctime>

int main() {
//    auto add1 = MathExpr::ExpressionFactory::createExpression(Addition, NULL, Basic);
//    auto sub1 = MathExpr::ExpressionFactory::createExpression(Subtraction, NULL, Basic);
//    auto mult = MathExpr::ExpressionFactory::createExpression(Multiplication, NULL, Basic);

    std::vector<MathOperation> operations;
    operations.insert(operations.end(), Addition);
    operations.insert(operations.end(), Subtraction);
    operations.insert(operations.end(), Multiplication);
    operations.emplace_back(Division);

    /*
    InfixConverter *infixConverter = new InfixConverter;

    time_t start_s = clock();
    // the code you wish to time goes here
    int i = 1000000;
    while (i > 0) {
        std::vector<ExprToken> exprTokens = ExprGenerator::generateExpression(operations, Normal);
        cout << infixConverter->exprToInfix(exprTokens) << endl;
        i--;
    }
    time_t stop_s = clock();
    cout << "time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;

    BinaryChallenge *binary = BinaryChallenge::generateBinaryQuestion(Normal);

    cout << binary->binary << " : " << binary->decimal << endl;

    auto *fact = new FactorizationGenerator();
    vector<int> int_list = fact->getExpandedParams("1+2-3");

    auto *lc = new LatexConverter();
    std::vector<ExprToken> lcExprTest = ExprGenerator::generateExpression(operations, Normal);
    std::string lcExprOutput = lc->exprToLatex(lcExprTest);
    cout << lcExprOutput << endl;
     */

    auto *lc = new LatexConverter();
    auto *ic = new InfixConverter();
    std::vector<ExprToken> exprTokens = ExprGenerator::generateExpression(operations, Basic);

    for (int i = 0; i < exprTokens.size(); i++) {
        cout << ExprToken::exprString(exprTokens[i]) << endl;
    }

    std::string lcExprOutput = lc->exprToLatex(exprTokens);
    std::string icExprOutput = ic->exprToInfix(exprTokens);
    cout << "\n" << lcExprOutput << endl;
    cout << icExprOutput << endl;

    cout << "exprToken generated successfully\n";

    return 0;
}

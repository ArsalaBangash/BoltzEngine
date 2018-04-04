#include <iostream>
#include "ExprGenerator.hpp"
#include "AdditionExpr.hpp"
#include "SubtractionExpr.hpp"
#include "EngineUtils.hpp"
#include "BinaryGenerator.hpp"
#include "InfixConverter.h"

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

    cout << "exprToken generated successfully\n";

    //cout << std::to_string(random(0, 1)) << endl;

    return 0;
}

#include <iostream>
#include "ExprGenerator.hpp"
#include "AdditionExpr.hpp"
#include "SubtractionExpr.hpp"
#include "EngineUtils.hpp"
#include "BinaryGenerator.hpp"
#include "FactorizationGenerator.hpp"

using namespace std;

int main() {
//    auto add1 = MathExpr::ExpressionFactory::createExpression(Addition, NULL, Basic);
//    auto sub1 = MathExpr::ExpressionFactory::createExpression(Subtraction, NULL, Basic);
//    auto mult = MathExpr::ExpressionFactory::createExpression(Multiplication, NULL, Basic);

    std::vector<MathOperation> operations;
    operations.insert(operations.end(), Addition);
    operations.insert(operations.end(), Subtraction);
    operations.insert(operations.end(), Multiplication);
    operations.emplace_back(Division);

    std::vector<ExprToken> exprTokens = ExprGenerator::generateExpression(operations, Basic);

    for (int i = 0; i < exprTokens.size(); i++) {
        cout << ExprToken::exprString(exprTokens[i]) << std::endl;
    }

    BinaryChallenge *binary = BinaryChallenge::generateBinaryQuestion(Normal);

    cout << binary->binary << " : " << binary->decimal << endl;

    FactorizationGenerator *fact = new FactorizationGenerator();
    fact->getExpandedParams("1+2-3");

    cout << "exprToken generated successfully\n";

    return 0;
}

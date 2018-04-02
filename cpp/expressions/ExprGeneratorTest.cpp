#include <iostream>
#include "ExprGenerator.hpp"
#include "AdditionExpr.hpp"
#include "SubtractionExpr.hpp"

using namespace std;
int main()
{
//    auto add1 = MathExpr::ExpressionFactory::createExpression(Addition, NULL, Basic);
//    auto sub1 = MathExpr::ExpressionFactory::createExpression(Subtraction, NULL, Basic);
//    auto mult = MathExpr::ExpressionFactory::createExpression(Multiplication, NULL, Basic);
    
    vector<MathOperation> operations;
    operations.insert(operations.end(), Addition);
    operations.insert(end(operations), Subtraction);
    operations.insert(end(operations), Multiplication);
    
    vector<ExprToken> exprTokens = ExprGenerator::generateExpression(operations, Basic);
    
    cout << "exprToken generated successfully\n";
    
    return 0;
}

#include <iostream>
#include "ExprGenerator.hpp"
#include "AdditionExpr.hpp"
#include "SubtractionExpr.hpp"

using namespace std;
int main()
{
    AdditionExpr add1 = MathExpr::ExpressionFactory::createExpression(Addition, NULL, Basic);
    SubtractionExpr sub1 = MathExpr::ExpressionFactory::createExpression(Subtraction, NULL, Basic);
    return 0;
}

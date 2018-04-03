#include "ExprGenerator.hpp"
#include "EngineUtils.hpp"

using namespace std;

/* Reduces the question of operations left in the current expression based on the location
 * of the empty tokens processed
 */
int ExprGenerator::reduceOperationsBy(SubExprLocation subExprLocation) {
    switch (subExprLocation) {
        case SubExprLocation::LEFT :
            return 1;
        case SubExprLocation::RIGHT :
            return 1;
        case SubExprLocation::BOTH :
            return 2;
        default :
            return 0;
    }
}

/* Based on the [operationsLeft] for a particular expression, this function
 * will return the locations for the empty tokens.
 */
SubExprLocation ExprGenerator::getEmptyTokenLocations(int operationsLeft) {
    switch (operationsLeft) {
        case 0 :
            return SubExprLocation::NEITHER;
        case 1 :
            return SubExprLocation::NEITHER;
        case 2 :
            if (random(0, 1) > 0.50) return SubExprLocation::LEFT;
            else return SubExprLocation::RIGHT;
        default :  // An equal 1/3 chance for all EmptyTokenLocations when there are more than 2 ops left
            double chooseNumEmpty = random(0, 1);
            if (chooseNumEmpty < 0.33) return SubExprLocation::BOTH;
            else if (chooseNumEmpty > 0.66) return SubExprLocation::LEFT;
            else return SubExprLocation::RIGHT;
    }
}

/* Given an ArrayList of MathOPerations and a Level parameter indicating the difficulty,
 * returns an expression in the form of an ArrayList of ExprTokens
 *
 * The expression returned will be in reverse polish notation
 * e.g. The expression (3 + (1 - 2)) will be [+, 3, -, 1, 2]s
 */
std::vector<ExprToken> ExprGenerator::generateExpression(std::vector<MathOperation> operations,
                                                         Level level) {
    int operationsLeft = static_cast<int>(operations.size());
    vector<ExprToken> expression;
    MathOperation currentOp = operations[random_index(operations.size())];

    // Determines whether the current operation will have numbers or sub-expressions on either side
    SubExprLocation subExprLocation = getEmptyTokenLocations(operationsLeft);

    operationsLeft -= reduceOperationsBy(subExprLocation);

    vector<MathOperation>::iterator position = find(operations.begin(), operations.end(), currentOp);
    if (position != operations.end()) operations.erase(position);

    MathExpr *expr = MathExpr::ExpressionFactory::createExpression(currentOp, NULL, level);
    vector<ExprToken> newExpressions = expr->produceExpression(subExprLocation);
    expression.insert(end(expression), begin(newExpressions), end(newExpressions));

    ExprWithSub *exprWithSub = checkSubExprTokens(expression);

    // While sub-expressions still exist, we'll continue to add to the expression
    while (exprWithSub != NULL) {
        currentOp = operations[random_index(operations.size())];
        subExprLocation = getEmptyTokenLocations(operationsLeft);
        expression = exprWithSub->leftSide;

        // Add the newly generated sub expression to the global expression
        if (exprWithSub->bound != NULL)
            expr = MathExpr::ExpressionFactory::createExpression(currentOp, exprWithSub->bound, level);
        else
            expr = MathExpr::ExpressionFactory::createExpression(currentOp, NULL, level);
        newExpressions = expr->produceExpression(subExprLocation);
        expression.insert(end(expression), begin(newExpressions), end(newExpressions));

        // Add the right side of the previously global expression and
        // check again for any Sub-Expression Tokens
        expression.insert(end(expression), begin(exprWithSub->rightSide), end(exprWithSub->rightSide));
        position = find(operations.begin(), operations.end(), currentOp);
        if (position != operations.end()) operations.erase(position);
        operationsLeft -= reduceOperationsBy(subExprLocation);
        exprWithSub = checkSubExprTokens(expression);
    }

    return expression;
}

/* Scans the [expressionList] for any sub-expression tokens. W
 * When one is found, the original expression is converted to a [ExprWithSub]
 * Returns the pointer to said [ExprWithSub], and returns NULL if no sub expression is found
 */
ExprGenerator::ExprWithSub *ExprGenerator::checkSubExprTokens(std::vector<ExprToken> expressionList) {
    ExprToken *token;
    for (int i = 0; i < expressionList.size(); i++) {
        token = &expressionList.at(i);
        if (token->hasSubExpr) {
            int bound = token->intVal;
            expressionList.erase(expressionList.begin() + i);
            vector<ExprToken> preEmptyTokens;
            preEmptyTokens.insert(preEmptyTokens.begin(), expressionList.begin(), expressionList.begin() + i - 1);
            vector<ExprToken> postEmptyTokens;
            postEmptyTokens.insert(postEmptyTokens.begin(), expressionList.begin() + i, expressionList.end());

            struct ExprWithSub *expr = new struct ExprWithSub;
            expr->bound = bound;
            expr->leftSide = preEmptyTokens;
            expr->rightSide = postEmptyTokens;

            return expr;
        }
    }
    return NULL;
}

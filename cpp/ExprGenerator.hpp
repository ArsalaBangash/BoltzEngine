#ifndef Expr_Generator_hpp
#define Expr_Generator_hpp

#include <vector>
#include <algorithm>
#include "Enums.h"
#include "ExprToken.hpp"
#include "MathExpr.hpp"

class ExprGenerator {
    struct ExprWithSub {
        bool isValid = false;
        int bound;
        std::vector<ExprToken> leftSide;
        std::vector<ExprToken> rightSide;
    };

    static int reduceOperationsBy(SubExprLocation);

    static SubExprLocation getEmptyTokenLocations(int);

    static struct ExprWithSub *checkSubExprTokens(std::vector<ExprToken>);

public:
    static std::vector<ExprToken> generateExpression(std::vector<MathOperation>, Level);

};

#endif

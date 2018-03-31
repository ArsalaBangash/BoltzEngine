#ifndef Expr_Generator_hpp
#define Expr_Generator_hpp

#include <vector>
#include <algorithm>
#include "Enums.h"
#include "ExprToken.hpp"
#include "MathExpr.hpp"

class ExprGenerator
{
	struct ExprWithSub
	{
        bool isValid = false;
		int bound;
		std::vector<ExprToken> leftSide;
		std::vector<ExprToken> rightSide;
    };

	int reduceOperationsBy(SubExprLocation);
	SubExprLocation getEmptyTokenLocations(int);
	std::vector<ExprToken> generateExpression(std::vector<MathOperation>, Level);
	struct ExprWithSub *checkSubExprTokens(std::vector<ExprToken>);
};

#endif

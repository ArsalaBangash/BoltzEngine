//
//  AdditionExpr.hpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-22.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#ifndef AdditionExpr_hpp
#define AdditionExpr_hpp

#include "ExprToken.hpp"
#include "MathExpr.hpp"

class AdditionExpr: public MathExpr
{
    void setMax(Level);
    void addZeroBoundTokens(SubExprLocation);
    void noSubExpressions();
    void twoSubExpressions();
    void oneSubExpression(SubExprLocation);
};

#endif /* AdditionExpr_hpp */

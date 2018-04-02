//
// Created by KyoKeun Park on 2018-04-02.
//

#ifndef ENGINE_MODULUSEXPR_H
#define ENGINE_MODULUSEXPR_H

#include "MathExpr.hpp"
#include "ExprToken.hpp"

class ModulusExpr: public MathExpr
{
    void setMax(Level);
    void addZeroBoundTokens(SubExprLocation);
    void noSubExpressions();
    void twoSubExpressions();
    void oneSubExpressions(SubExprLocation);

public:
    ModulusExpr(MathOperation mathOperation) : MathExpr(mathOperation) {}
};

#endif //ENGINE_MODULUSEXPR_H

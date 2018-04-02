//
//  DivisionExpr.hpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-04-02.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#ifndef DivisionExpr_hpp
#define DivisionExpr_hpp

#include "MathExpr.hpp"
#include "ExprToken.hpp"

class DivisionExpr: public MathExpr
{
    void setMax(Level);
    void addZeroBoundTokens(SubExprLocation);
    void noSubExpressions();
    void twoSubExpressions();
    void oneSubExpression(SubExprLocation);

public:
    DivisionExpr(MathOperation mathOperation) : MathExpr(mathOperation) {}
    
private:
    int generateDivisor(int);
};

#endif /* DivisionExpr_hpp */

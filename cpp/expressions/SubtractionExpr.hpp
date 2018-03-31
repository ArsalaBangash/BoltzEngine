//
//  SubtractionExpr.hpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-22.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#ifndef SubtractionExpr_hpp
#define SubtractionExpr_hpp

#include "ExprToken.hpp"
#include "MathExpr.hpp"

class SubtractionExpr: public MathExpr
{
    void setMax(Level);
    void addZeroBoundTokens(SubExprLocation);
    void noSubExpressions();
    void twoSubExpressions();
    void oneSubExpressions(SubExprLocation);
    
public:
    SubtractionExpr(MathOperation mathOperation) : MathExpr(mathOperation) {}

};

#endif /* SubtractionExpr_hpp */

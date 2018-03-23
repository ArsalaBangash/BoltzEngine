//
//  MultiplicationExpr.hpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-22.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#ifndef MultiplicationExpr_hpp
#define MultiplicationExpr_hpp

#include "ExprToken.hpp"
#include "MathExpr.hpp"

class MultiplcationExpr: public MathExpr
{
    void setMax(Level);
    void addZeroBoundTokens(SubExprLocation);
    void noSubExpressions();
    void twoSubExpressions();
    void oneSubExpressions(SubExprLocation);
    
private:
    std::vector<int> multiples;
};

#endif /* MultiplicationExpr_hpp */

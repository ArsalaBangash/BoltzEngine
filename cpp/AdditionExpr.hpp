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

class AdditionExpr : public MathExpr {
public:
    explicit AdditionExpr(MathOperation mathOperation) : MathExpr(mathOperation) {}

protected:
    void setMax(Level) override;

    void addZeroBoundTokens(SubExprLocation) override;

    void noSubExpressions() override;

    void twoSubExpressions() override;

    void oneSubExpression(SubExprLocation) override;
};

#endif /* AdditionExpr_hpp */

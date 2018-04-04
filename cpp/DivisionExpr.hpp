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

class DivisionExpr : public MathExpr {
    void setMax(Level) override;

    void addZeroBoundTokens(SubExprLocation) override;

    void noSubExpressions() override;

    void twoSubExpressions() override;

    void oneSubExpression(SubExprLocation) override;

public:
    explicit DivisionExpr(MathOperation mathOperation) : MathExpr(mathOperation) {}

private:
    int generateDivisor(int);
};

#endif /* DivisionExpr_hpp */

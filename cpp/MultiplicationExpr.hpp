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

class MultiplicationExpr : public MathExpr {
    void setMax(Level) override;

    void addZeroBoundTokens(SubExprLocation) override;

    void noSubExpressions() override;

    void twoSubExpressions() override;

    void oneSubExpression(SubExprLocation) override;

    std::vector<ExprToken> produceExpression(SubExprLocation) override;

public:
    explicit MultiplicationExpr(MathOperation mathOperation) : MathExpr(mathOperation) {}

private:
    std::vector<std::vector<int> > multiples;
};

#endif /* MultiplicationExpr_hpp */

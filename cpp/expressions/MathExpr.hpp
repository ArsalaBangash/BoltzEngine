//
//  MathExpr.hpp
//  
//
//  Created by KyoKeun Park on 2018-03-20.
//

#ifndef MathExpr_hpp
#define MathExpr_hpp

#include <stdio.h>
#include <vector>
#include "ExprToken.hpp"

class MathExpr
{

    class ExpressionFactory
    {
    public:
        MathExpr createExpression(MathOperation expressionType, int bound, Level level);
    };

public:
    bool isBounded = false;
    std::vector<ExprToken> expression;
    int bound = UNDEFINED;
    int MAX = 0;
    int MIN = 0;
    MathOperation mathOperation;
    
    /* Constructor for the MathExpr */
    MathExpr(MathOperation mathOperation);
    
    /*
     * Every concrete implmentation of a MathExpr generates its expression in polish notation
     * by first adding it's MathOperation and then depending on the location of its subexpression and
     * whether or not the expression is bounded
     */
    std::vector<ExprToken> produceExpression(SubExprLocation subExprLocation);
    
protected:
    /* Adds operands to the MathExpr */
    virtual void noSubExpressions();
    
    /* Adds subexpressions to the MathExpr */
    virtual void twoSubExpressions();
    
    /* Depending on whether a sub-expression will be on the left or right, this function will
     * add an operand and a subexpression accordingly */
    virtual void oneSubExpression(SubExprLocation subExprLocation);
    
    /* When the MathEExpr is bounded by a value of 0, operands are added accordingly */
    virtual void addZeroBoundTokens(SubExprLocation subExprLocation);
    
    /* Sets the maximum value for an operand based on the [difficulty] of the expression */
    virtual void setMax(Level level);
    
private:
    /* Lets the implementation of MathExpr know that it is a bounded sub-expression */
    void setBound(int bound);
};

#endif /* MathExpr_hpp */

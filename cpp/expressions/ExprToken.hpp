//
//  ExprToken.hpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-22.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#ifndef ExprToken_hpp
#define ExprToken_hpp

#include "Enums.h"

class ExprToken
{
    int intVal = UNDEFINED;
    MathOperation mathOperation;
    bool hasSubExpr = UNDEFINED;
public:
    ExprToken(int intVal, MathOperation mathOperation, bool hasSubExpr);
    ExprToken(int intVal, MathOperation mathOperation);
    ExprToken(int intVal, bool hasSubExpr);
    ExprToken(int intVal);
    ExprToken(MathOperation mathOperation);
    ExprToken(bool hasSubExpr);
};

#endif /* ExprToken_hpp */

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

class ExprToken {
    MathOperation mathOperation;
public:
    ExprToken(int intVal, MathOperation mathOperation, bool hasSubExpr);

    ExprToken(int intVal, MathOperation mathOperation);

    ExprToken(int intVal, bool hasSubExpr);

    ExprToken(int intVal);

    ExprToken(MathOperation mathOperation);

    ExprToken(bool hasSubExpr);

    bool hasSubExpr = UNDEFINED;
    int intVal = UNDEFINED;
};

#endif /* ExprToken_hpp */

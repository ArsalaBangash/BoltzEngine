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
#include <string>

class ExprToken {
    MathOperation mathOperation;
public:
    ExprToken(int intVal, MathOperation mathOperation, bool hasSubExpr);

    ExprToken(int intVal, MathOperation mathOperation);

    ExprToken(int intVal, bool hasSubExpr);

    ExprToken(int intVal);

    ExprToken(MathOperation mathOperation);

    ExprToken(bool hasSubExpr);

    bool hasSubExpr = false;
    int intVal = UNDEFINED;

    static std::string exprString(ExprToken exprToken) {
        if (exprToken.mathOperation) {
            std::string mathOpString;
            switch (exprToken.mathOperation) {
                case Addition:
                    mathOpString = "Addition";
                    break;
                default:
                    mathOpString = "Addition";
                    break;
            }
            return mathOpString;
        } else return std::to_string(exprToken.intVal);
    }

};

#endif /* ExprToken_hpp */

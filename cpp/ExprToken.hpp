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

public:
    ExprToken(int intVal, MathOperation mathOperation, bool hasSubExpr);

    ExprToken(int intVal, MathOperation mathOperation);

    ExprToken(int intVal, bool hasSubExpr);

    explicit ExprToken(int intVal);

    explicit ExprToken(MathOperation mathOperation);

    explicit ExprToken(bool hasSubExpr);

    bool hasSubExpr = false;
    int intVal = UNDEFINED;
    MathOperation mathOperation = Invalid;

    static std::string exprString(ExprToken exprToken) {
        if (exprToken.intVal == -999) {
            std::string mathOpString;
            switch (exprToken.mathOperation) {
                case Addition:
                    mathOpString = "Addition";
                    break;
                case Subtraction:
                    mathOpString = "Subtraction";
                    break;
                case Multiplication:
                    mathOpString = "Multiplication";
                    break;
                case Division:
                    return "Division";
                case Modulus:
                    return "Modulus";
                default:
                    return std::to_string(exprToken.intVal);
            }
            return mathOpString;
        }
        return std::to_string(exprToken.intVal);
    }

};

#endif /* ExprToken_hpp */

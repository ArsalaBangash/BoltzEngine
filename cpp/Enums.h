
#ifndef enums_h
#define enums_h

typedef enum
{
    Basic,
    Noraml,
    Advanced
} Level;

typedef enum
{
    Addition,
    Subtraction,
    Multiplication,
    Exponent,
    Modulus,
    Division
} MathOperation;

typedef enum
{
    NEITHER,
    BOTH,
    LEFT,
    RIGHT
} SubExprLocation;

#endif

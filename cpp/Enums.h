
#ifndef enums_h
#define enums_h

#define UNDEFINED 0 - 999;

typedef enum {
    Basic,
    Normal,
    Advanced
} Level;

typedef enum {
    Addition,
    Subtraction,
    Multiplication,
    Exponent,
    Modulus,
    Division,
    Invalid
} MathOperation;

typedef enum {
    NEITHER,
    BOTH,
    LEFT,
    RIGHT
} SubExprLocation;

#endif

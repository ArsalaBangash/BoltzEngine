project(BoltzEngine)
set(CMAKE_CXX_STANDARD 11)
add_executable(ExprGeneratorTest InfixConverter.cpp ExprGeneratorTest.cpp ExprGenerator.cpp Enums.h DivisionExpr.cpp ModulusExpr.cpp EngineUtils.cpp MathExpr.cpp SubtractionExpr.cpp MultiplicationExpr.cpp AdditionExpr.cpp ExprToken.cpp BinaryGenerator.cpp)

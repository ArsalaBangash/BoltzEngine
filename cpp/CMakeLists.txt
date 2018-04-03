project(BoltzEngine)
set(CMAKE_CXX_STANDARD 11)
add_executable(ExprGeneratorTest ExprGeneratorTest.cpp ExprGenerator.cpp Enums.h EngineUtils.cpp MathExpr.cpp SubtractionExpr.cpp MultiplicationExpr.cpp AdditionExpr.cpp ExprToken.cpp)
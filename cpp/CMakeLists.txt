cmake_minimum_required(VERSION 3.10)

project(BoltzEngine)

message(STATUS "starting to run cmake...")

set(CMAKE_CXX_STANDARD 11)
#set(OPTIMIZATION_OPT "-o1")
#set(BASE_OPTIONS "-pedantic-errors -Wall -Wextra -Werror -Wno-long-long")
#set(OPTIONS "${BASE_OPTIONS} ${OPTIMIZATION_OPT}")
#set (CMAKE_CXX_FLAGS "${OPTIONS}")

find_package(Boost 1.66.0 COMPONENTS REQUIRED regex)

include_directories(sym_cpp)

if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

    add_executable(ExprGeneratorTest InfixConverter.cpp ExprGeneratorTest.cpp ExprGenerator.cpp Enums.h DivisionExpr.cpp ModulusExpr.cpp EngineUtils.cpp MathExpr.cpp SubtractionExpr.cpp MultiplicationExpr.cpp AdditionExpr.cpp ExprToken.cpp BinaryGenerator.cpp FactorizationGenerator.cpp FactorizationGenerator.hpp LatexConverter.cpp LatexConverter.hpp LatexConverter.cpp)

    target_link_libraries(ExprGeneratorTest ${Boost_LIBRARIES})
endif ()

add_executable(exprtk_test exprtk_test.cpp exprtk.hpp InfixConverter.cpp ExprGenerator.cpp Enums.h DivisionExpr.cpp ModulusExpr.cpp EngineUtils.cpp MathExpr.cpp SubtractionExpr.cpp MultiplicationExpr.cpp AdditionExpr.cpp ExprToken.cpp BinaryGenerator.cpp)

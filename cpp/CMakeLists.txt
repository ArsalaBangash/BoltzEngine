cmake_minimum_required(VERSION 3.10)

project(BoltzEngine)

message(STATUS "starting to run cmake...")

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.66.0 COMPONENTS REQUIRED regex)

if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

    add_executable(ExprGeneratorTest InfixConverter.cpp ExprGeneratorTest.cpp ExprGenerator.cpp Enums.h DivisionExpr.cpp ModulusExpr.cpp EngineUtils.cpp MathExpr.cpp SubtractionExpr.cpp MultiplicationExpr.cpp AdditionExpr.cpp ExprToken.cpp BinaryGenerator.cpp FactorizationGenerator.cpp FactorizationGenerator.hpp LatexConverter.cpp LatexConverter.hpp LatexConverter.cpp HexGenerator.cpp HexGenerator.hpp)

    target_link_libraries(ExprGeneratorTest ${Boost_LIBRARIES})
endif()

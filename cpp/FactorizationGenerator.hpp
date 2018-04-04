//
// Created by KyoKeun Park on 2018-04-03.
//

#ifndef BOLTZENGINE_FACTORIZATIONGENERATOR_HPP
#define BOLTZENGINE_FACTORIZATIONGENERATOR_HPP

#include <vector>
#include "Enums.h"

class FactorizationGenerator {

private:
    int xCoeffMax = 1;
    int constMax = 5;

public:
    struct FactorParams {
        int xCoeff1, xCoeff2, const1, const2;
    };

    void setMax(Level);
    FactorParams generateFactorParams(Level);
    std::vector<int> getExpandedParams(std::string);
};

#endif //BOLTZENGINE_FACTORIZATIONGENERATOR_HPP

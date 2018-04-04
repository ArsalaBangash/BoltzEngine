//
// Created by KyoKeun Park on 2018-04-04.
//

#ifndef BOLTZENGINE_HEXGENERATOR_HPP
#define BOLTZENGINE_HEXGENERATOR_HPP

#include <string>
#include "Enums.h"

struct HexChallenge {
    std::string decimal, hex;
    bool hexToDec;
};

HexChallenge generateHexQuestion(Level);
std::pair<std::string, std::string> getHexDecPair(Level);

#endif //BOLTZENGINE_HEXGENERATOR_HPP

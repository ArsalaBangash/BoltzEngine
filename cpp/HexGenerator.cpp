//
// Created by KyoKeun Park on 2018-04-04.
//

#include <iomanip>
#include <sstream>
#include <string>
#include "HexGenerator.hpp"
#include "EngineUtils.hpp"

HexChallenge generateHexQuestion(Level level) {
    std::pair<std::string, std::string> hexDecPair = getHexDecPair(level);
    if (random(0, 1) > 0.50)
        return HexChallenge { hexDecPair.first, hexDecPair.second, true };
    else
        return HexChallenge { hexDecPair.first, hexDecPair.second, false };
}

std::pair<std::string, std::string> getHexDecPair(Level level) {
    int decimal = 0;
    std::stringstream stream;
    stream << "0x";

    switch (level) {
        case Level::Basic :
            decimal = (generatePositiveRandom(32) + 1);
            break;
        case Level::Normal :
            decimal = (generatePositiveRandom(4, 128) + 1);
            break;
        case Level::Advanced :
            decimal = (generatePositiveRandom(32, 256) + 1);
            break;
    }

    stream << std::hex << decimal;
    return std::pair<std::string, std::string>(std::to_string(decimal), stream.str());
}
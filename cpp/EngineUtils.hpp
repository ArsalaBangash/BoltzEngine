//
//  EngineUtils.hpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-19.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#ifndef EngineUtils_hpp
#define EngineUtils_hpp

#include <random>
#include <string>
#include <stack>

double random(int min, int max);

unsigned long random_index(unsigned long max);

int generateNonZero(int absoluteRange);

int generatePositiveRandom(int min, int max);

int generatePositiveRandom(int max);

int generatePosNegRandom(int range);

std::string getAndPop(std::stack<std::string>);

#endif /* EngineUtils_hpp */

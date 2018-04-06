//
// Created by Arsala Bangash on 2018-04-02.
//

#ifndef PROJECT_ENGINEAPP_H
#define PROJECT_ENGINEAPP_H

#include <string>
#include "Enums.h"

struct ChallengeReps {
    std::string infixRepr;
    std::string latexRepr;
};

bool checkAnswer(const std::string&, const std::string&);
ChallengeReps genExpression(std::string, Level);

#endif //PROJECT_ENGINEAPP_H

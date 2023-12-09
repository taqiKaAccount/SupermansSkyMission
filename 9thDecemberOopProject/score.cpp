#pragma once
#include "score.hpp"

int score::getScore() {
    return score;
};

void score::increaseScore(bool DidCollisionOccur) {
    if ( DidCollisionOccur )
    {
        score = score + 1;
    }
    
}
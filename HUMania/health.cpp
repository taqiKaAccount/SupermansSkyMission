#pragma once
#include "health.hpp"

int health::getLife() {
    return life ;
};

void health::reduceHealth() {
    life = life -1;
}
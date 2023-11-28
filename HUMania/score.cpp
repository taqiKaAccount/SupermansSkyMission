#pragma once
#include "score.hpp"

    //do op overlloading for increments/decrements of 10
Score& Score::operator++(){
        ScoreCount+=10 ;
        return *this; 
    }

Score& Score::operator--(){
        ScoreCount-=10 ;
        return *this; 
    }



int Score::getScore()const{
        return ScoreCount ;
    }

Score::Score(): ScoreCount(0) {};
//score constructor
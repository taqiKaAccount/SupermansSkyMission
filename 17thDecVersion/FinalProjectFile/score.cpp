#pragma once
#include "score.hpp"
#include <SDL_ttf.h>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "drawing.hpp"
using namespace std;
#include "score.hpp"

Score::Score() : ScoreCount(0), ftexture(nullptr), t_width(50), t_height(50) {}
int Score::getScore() const {
    return ScoreCount;
}
Score& Score::operator++() {
    ScoreCount += 10;
    return *this;
}

Score Score::operator++(int) {
    Score temp(*this);
    operator++();
    return temp;
}

Score& Score::operator--() {
    ScoreCount -= 50;
    return *this;
}

Score Score::operator--(int) {
    Score temp(*this);
    operator--();
    return temp;
}

void Score::draw(SDL_Renderer* renderer) {
    int fontSize = 50;
    SDL_Color text_color = { 0, 0, 0 };
    string fontPath = "PixelSport-nRVRV.ttf";
    string text = "Score: " + to_string(ScoreCount);

    // Check if font is loaded successfully
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (font == NULL) {
        cerr << "Failed to load the font!\n";
        cerr << "SDL_TTF Error: " << TTF_GetError() << "\n";
        cerr << "Font Path: " << fontPath << endl;
        return; // Return without rendering if font load fails
    }

    SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);

    if (text_surface == NULL) {
        cerr << "Failed to render text surface!\n";
        cerr << "SDL_TTF Error: " << TTF_GetError() << "\n";
    } else {
        ftexture = SDL_CreateTextureFromSurface(renderer, text_surface);

        if (ftexture == NULL) {
            cerr << "Unable to create texture from rendered text!\n";
            cerr << "SDL Error: " << SDL_GetError() << "\n";
        } else {
            t_width = text_surface->w;
            t_height = text_surface->h;

            // Adjust position as needed
            SDL_Rect destinationRect = { 900, 900, t_width, t_height };
            SDL_RenderCopy(renderer, ftexture, NULL, &destinationRect);
            SDL_FreeSurface(text_surface);
        }
    }

    TTF_CloseFont(font); // Close the font after rendering
}

void Score::render(SDL_Renderer* renderer,int x,int y,int w,int h) {
    // Adjust position as needed
    SDL_Rect destinationRect = { x, y, w, h };
    SDL_RenderCopy(renderer, ftexture, NULL, &destinationRect);
}


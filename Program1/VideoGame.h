/*******************************
    File:   VideoGame.h
    Author: Austin Ring
    Date:   2/13/21
********************************/
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Text.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class VideoGame{
    private:
        Text *title, *platform, *genre, *ageRating;
        int year, userRating;
    public:
        VideoGame(Text*, Text*, int, Text*, Text*, int);
        ~VideoGame();
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(ofstream &);
        Text* getVideoGameTitle() const;
};

#endif
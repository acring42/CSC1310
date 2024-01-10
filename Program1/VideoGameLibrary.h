/*******************************
    File:   VideoGameLibrary.h
    Author: Austin Ring
    Date:   2/13/21
********************************/
#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include "VideoGame.h"
#include <iostream>
#include <fstream>
using namespace std;

class VideoGameLibrary{
    private:
        VideoGame** videoGamesArray;
        int maxGames, numGames;

    public:
        VideoGameLibrary(int);
        ~VideoGameLibrary();
        void resizeVideoGameArray();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(string);
        void removeVideoGameFromArray();
        void saveToFile(string);
};

#endif
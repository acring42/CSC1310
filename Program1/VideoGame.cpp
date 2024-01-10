/*******************************
    File:   VideoGame.cpp
    Author: Austin Ring
    Date:   2/13/21
********************************/
#include "VideoGame.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VideoGame::VideoGame(Text* t, Text* p, int y, Text* g, Text* a, int u){
    title = t;
    platform = p;
    year = y;
    genre = g;
    ageRating = a;
    userRating = u;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VideoGame::~VideoGame(){
    delete title;
    delete platform;
    delete genre;
    delete ageRating;
    cout << "\nVideoGame Destructor: Released memory for title, platform, genre, and age rating." << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VideoGame::printVideoGameDetails(){
    cout << "\n\tGame Title: ";
    title->displayText();
    cout << "\n\tPlatform: ";
    platform->displayText();
    cout << "\n\tYear Released: " << year << endl;
    cout << "\tGenre: ";
    genre->displayText();
    cout << "\n\tRating: ";
    ageRating->displayText();
    cout << "\n\tNumber of Stars: " << userRating;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VideoGame::printVideoGameDetailsToFile(ofstream &file){
    char tempC[100];
    strncpy(tempC, title->getText(), 100);
    file << tempC << endl;
    strncpy(tempC, platform->getText(), 100);
    file << tempC << endl;
    file << year << endl;
    strncpy(tempC, genre->getText(), 100);
    file << tempC << endl;
    strncpy(tempC, ageRating->getText(), 100);
    file << tempC << endl;
    file << userRating << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Text* VideoGame::getVideoGameTitle() const{
    return this->title;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
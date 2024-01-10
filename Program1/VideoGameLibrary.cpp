/*******************************
    File:   VideoGameLibrary.cpp
    Author: Austin Ring
    Date:   2/13/21
********************************/
#include "VideoGameLibrary.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VideoGameLibrary::VideoGameLibrary(int max){
    this->maxGames = max;
    this->numGames = 0;
    videoGamesArray = new VideoGame*[maxGames];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VideoGameLibrary::~VideoGameLibrary(){
    for(int i=0; i<numGames; i++)
        delete videoGamesArray[i];
    delete videoGamesArray;
    cout << "\nVideoGameLibrary Destructor: Released memory for each game in the video game array and the array itself." << endl;
    cout << "\nGoodbye!" << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VideoGameLibrary::resizeVideoGameArray(){
    int maxTemp = maxGames*2;
    VideoGame** videoGamesArray2 = new VideoGame*[maxTemp];
    
    for(int i=0; i<numGames; i++){
        videoGamesArray2[i] = videoGamesArray[i];
    }
    delete videoGamesArray;
    videoGamesArray = videoGamesArray2;
    
    cout << "\t*Resizing array from " << maxGames << " to " << maxTemp << ".*" << endl;
    maxGames = maxTemp;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VideoGameLibrary::addVideoGameToArray(){
    char array[100];
    Text* title, *platform, *genre, *ageRating;
    int year, userRating;

    cout << "\nEnter Game Title" << endl;
    cin.getline(array, 100, '\n');
    title = new Text(array);
    cout << "Enter Game Platform" << endl;
    cin.getline(array, 100, '\n');
    platform = new Text(array);
    cout << "Enter Game Year" << endl;
    cin >> year;
    cin.ignore();
    cout << "Enter Game Genre" << endl;
    cin.getline(array, 100, '\n');
    genre = new Text(array);
    cout << "Enter Age Rating" << endl;
    cin.getline(array, 100, '\n');
    ageRating = new Text(array);
    cout << "Enter User Rating" << endl;
    cin >> userRating;
    cin.ignore();

    VideoGame* newGame = new VideoGame(title, platform, year, genre, ageRating, userRating);
    
    if(numGames == maxGames)
        resizeVideoGameArray();

    videoGamesArray[numGames] = newGame;
    numGames++;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VideoGameLibrary::displayVideoGames(){

    if(numGames<1)
        cout << "There are no games to display!" << endl;
    else{
        for(int i=0; i<numGames; i++){
            cout << "\nMovie " << i+1;
            videoGamesArray[i]->printVideoGameDetails();
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VideoGameLibrary::displayVideoGameTitles(){
    Text* title;

    for(int i=0; i<numGames; i++){
        cout << "\nMovie " << (i+1) << ": ";
        title = videoGamesArray[i]->getVideoGameTitle();
        title->displayText();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VideoGameLibrary::loadVideoGamesFromFile(string filename){
    VideoGame* game;
    int numRead, size = 10000;
    ifstream file;
    char tempC[size];
    Text* title, *platform, *genre, *ageRating;
    int year, userRating;

    file.open(filename);
    if(file.good()){
        while(!file.eof()){
            file.getline(tempC, size);
            title = new Text(tempC);
            file.getline(tempC, size);
            platform = new Text(tempC);
            file >> year;
            file.ignore();
            file.getline(tempC, size);
            genre = new Text(tempC);
            file.getline(tempC, size);
            ageRating = new Text(tempC);
            file >> userRating;
            file.ignore();

            game = new VideoGame(title, platform, year, genre, ageRating, userRating);
            if(numGames == maxGames)
                resizeVideoGameArray();
            
            videoGamesArray[numGames] = game;
            numGames++;
            title->displayText();
            cout << " was added to the video game library!" << endl;
            numRead++;
        }
        cout << "\n" << numRead << " games were read from the file and added to the library!" << endl;
    }
    else    
        cout << "\nUnable to open file!" << endl;

    file.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VideoGameLibrary::removeVideoGameFromArray(){
    int choice;
    int newNumGames = numGames-1;
    Text* title;

    if (numGames<1)
        cout << "No games to remove" << endl;
    else{
        cout << "\nChoose a game to remove:" << endl;
        displayVideoGameTitles();
        cout << "\nPick a number between 1 and " << numGames << ":" << endl;
        cin >> choice;
        while(choice<1 || choice>numGames){
            cout << "Invalid Response! Please pick a number between 1 and " << numGames << "!" << endl;
            cin >> choice;
        }

        title = videoGamesArray[choice-1]->getVideoGameTitle();

        cout << "\nThe video game, ";
        title->displayText();
        cout << ", has been removed from the library!" << endl;

        delete videoGamesArray[choice-1];

        for(int i=(choice-1); i<newNumGames; i++)
            videoGamesArray[i] = videoGamesArray[i+1];
        numGames--;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VideoGameLibrary::saveToFile(string filename){
    ofstream file;
    file.open(filename);
    
    for(int i=0; i<numGames; i++){
        videoGamesArray[i]->printVideoGameDetailsToFile(file);
    }
    file.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
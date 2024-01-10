#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"

int main(){
    VideoGameLibrary* vglObj;
    int size, choice;
    string nameFile1, nameFile2;
    cout << "\nHow many video games can your library hold?" << endl;
    cin >> size;
    vglObj = new VideoGameLibrary(size);

    do{
        cout << "\nWhat would you like to do?" << endl;
        cout << "1.  Load video games from file" << endl;
        cout << "2.  Save video games to a file" << endl;
        cout << "3.  Add a video game" << endl;
        cout << "4.  Remove a video game" << endl;
        cout << "5.  Display all video games" << endl;
        cout << "6.  Remove ALL video games from this library and end program" << endl;
        cout << "Choose 1-6:" << endl;
        cin >> choice;
        while(choice>6 || choice<1){
            cout << "Invalid Response! Please enter 1-6." << endl;
            cin >> choice;
        }
        cin.ignore();

        switch(choice){
            case 1:
                cout << "Name of File? (ex. FileName.txt)" << endl;
                getline(cin, nameFile1);
                vglObj->loadVideoGamesFromFile(nameFile1);
                break;
            case 2:
                cout << "Name of File? (ex. FileName.txt)" << endl;
                getline(cin, nameFile2);
                vglObj->saveToFile(nameFile2);
                break;
            case 3:
                vglObj->addVideoGameToArray();
                break;
            case 4:
                vglObj->removeVideoGameFromArray();
                break;
            case 5:
                vglObj->displayVideoGames();
                break;
            case 6:
                delete vglObj;
                return 0;
                break;
        }

    }while(choice > 0 && choice < 7);
    
    return 0;
}
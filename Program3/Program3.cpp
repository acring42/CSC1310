/**********************************************************************
	Title:        Program3.cpp
	Author:       Austin Ring
	Date Created: 3/29/2021
***********************************************************************/
#include "BinaryTree.h"
#include "Pokemon.h"

int main(){
    BinaryTree<Pokemon*> PokeObj;
    int index;
    string name;

    int numPoke = 0;
    ifstream file;
    file.open("pokedex.txt");
    while(!file.eof()){
        file >> index;
        file.ignore();
        getline(file, name, '#');
        Pokemon* newObject = new Pokemon(index, name);
        if(PokeObj.searchNode(newObject)==false){
            PokeObj.insertNode(newObject);
            numPoke++;
            cout << "Inserting Pokemon with index " << index << " into the Pokedex." << endl;
        }
        else
            cout << "Oops! The Pokemon with index " << index << " is already in the Pokedex." << endl;
    }
    file.close();
    cout << endl << numPoke << " Pokemon have been added to the Pokedex!" << endl;
    cout << "\n******************************POKEDEX**********************************" << endl;
    PokeObj.displayInOrder();

    return 0;
}
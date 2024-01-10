/**********************************************************************
	Title:        Pokemon.h
	Author:       Austin Ring
	Date Created: 3/29/2021
***********************************************************************/
#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
using namespace std;

class Pokemon{
    private:
        int index;
        string name;

    public:
        Pokemon(){
            index = 0;
            name = "NONE";
        }
        Pokemon(int i, string n){
            this->index = i;
            this->name = n;
        }
        void setID(int i){
            index = i;
        }
        void setName(string n){
            name = n;
        }
        int getID() const{
            return index;
        }
        string getName() const{
            return name;
        }

        bool operator <(const Pokemon& p){
            if(this->index < p.index)
                return true;
            else
                return false;
        }

        bool operator ==(const Pokemon& p){
            if(this->index == p.index)
                return true;
            else
                return false;
        }

        friend ostream & operator <<(ostream & os, Pokemon &p){
            os << "\nPokemon Index Number: " << p.index;
            os << "        Name: " << p.name;
            return os;
        }
};

#endif
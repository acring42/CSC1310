/*******************************
    File:   Text.h
    Author: Austin Ring
    Date:   2/13/21
********************************/
#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <cstring>
using namespace std;

class Text{
    private:
        const char* textArray;
        int textLength;
    public:
        Text(const char*);
        ~Text();
        void displayText();
        const char* getText();
        int getLength(string) const;
};

#endif
#ifndef PLANET_H
#define PLANET_H

#include <iostream>
using namespace std;

class Planet{
    private:
        int minTemp, maxTemp, radius;

    public:
        Planet();
        ~Planet(){
            cout << "\nDestroying a Planet!\n" << endl;
        }
        
        void setMinTemp(int temp1);
        void setMaxTemp(int temp2);
        void setRadius(int rad);

        int getMinTemp() const;
        int getMaxTemp() const;
        int getRadius() const;
};

#endif
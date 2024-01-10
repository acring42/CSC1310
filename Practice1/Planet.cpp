#include "planet.h"

Planet::Planet(){
    minTemp = 0;
    maxTemp = 0;
    radius = 0;
    cout << "\nCreating a Planet!\n" << endl;
}

void Planet::setMinTemp(int temp1){
    minTemp = temp1;
}
void Planet::setMaxTemp(int temp2){
    maxTemp = temp2;
}
void Planet::setRadius(int rad){
    radius = rad;
}

int Planet::getMinTemp() const{
    return minTemp;
}
int Planet::getMaxTemp() const{
    return maxTemp;
}
int Planet::getRadius() const{
    return radius;
}
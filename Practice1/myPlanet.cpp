#include "planet.h"

int main(){
    Planet myPlanet;

    myPlanet.setMinTemp(4);
    myPlanet.setMaxTemp(10);
    myPlanet.setRadius(3);

    cout << myPlanet.getMinTemp() << endl;
    cout << myPlanet.getMaxTemp() << endl;
    cout << myPlanet.getRadius() << endl;

    return 0;
}
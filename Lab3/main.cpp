#include "functions.h"


int main() {
    int n = enterSizeArray();
    Plane *planes = new Plane[n];
    createArray(planes, n);
    findPlaneContainPoint(planes, n);
    delete [] planes;
    return 0;
}

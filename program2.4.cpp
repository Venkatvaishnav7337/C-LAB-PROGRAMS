#include <iostream>
#include <cmath> // Required for M_PI (or manual pi definition)

using namespace std;

// 1. Volume of a Cube (1 argument: side length)
double volume(double side) {
    return side * side * side;
}

// 2. Volume of a Cuboid (3 arguments: length, width, height)
double volume(double length, double width, double height) {
    return length * width * height;
}

// 3. Volume of a Cylinder (2 arguments: radius, height)
double volume(double radius, double height) {
    const double PI = 3.141592653589793;
    return PI * radius * radius * height;
}

int main() {
    // Test Cube Volume
    double cubeSide = 4.0;
    cout << "Volume of Cube (side = " << cubeSide << "): " 
         << volume(cubeSide) << "\n";

    // Test Cuboid Volume
    double l = 3.0, w = 4.0, h = 5.0;
    cout << "Volume of Cuboid (" << l << "x" << w << "x" << h << "): " 
         << volume(l, w, h) << "\n";

    // Test Cylinder Volume
    double r = 3.0, cylHeight = 7.0;
    cout << "Volume of Cylinder (radius = " << r << ", height = " << cylHeight << "): " 
         << volume(r, cylHeight) << "\n";

    return 0;
}

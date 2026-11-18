#include <iostream>

using namespace std;

// 1. Inline function to find the minimum of two integers
inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

// 2. Inline function to find the minimum of three integers
// It reuses the two-argument overload internally for clean code
inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    int x = 15, y = 7, z = 22;

    // Test the 2-argument overload
    cout << "Minimum of " << x << " and " << y << " is: " 
         << minVal(x, y) << "\n";

    // Test the 3-argument overload
    cout << "Minimum of " << x << ", " << y << ", and " << z << " is: " 
         << minVal(x, y, z) << "\n";

    // Additional test where the third value is the smallest
    cout << "Minimum of 45, 12, and 3 is: " 
         << minVal(45, 12, 3) << "\n";

    return 0;
}

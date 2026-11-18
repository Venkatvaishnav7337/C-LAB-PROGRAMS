#include <iostream>

using namespace std;

// Function declaration with a default argument for the exponent
int power(int base, int exp = 2) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    // 1. Calling with 1 argument uses the default exponent (2)
    cout << "power(5)    = " << power(5) << " (Expected: 25)\n";

    // 2. Calling with 2 arguments overrides the default exponent
    cout << "power(2, 10) = " << power(2, 10) << " (Expected: 1024)\n";

    // 3. Another test with a manual exponent value
    cout << "power(3, 4)  = " << power(3, 4) << " (Expected: 81)\n";

    return 0;
}

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor to initialize default values
    Complex() : real(0.0), imag(0.0) {}

    // Method to set data for a complex number
    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    // Method to display the complex number in standard format (a + bi)
    void display() const {
        if (imag >= 0) {
            std::cout << real << " + " << imag << "i";
        } else {
            // Properly handle negative imaginary parts (e.g., 2 - 3i instead of 2 + -3i)
            std::cout << real << " - " << -imag << "i";
        }
    }
};

int main() {
    const int SIZE = 3;
    Complex numberArray[SIZE];

    // Setting data for the array of complex numbers
    numberArray[0].setData(3.5, 4.5);
    numberArray[1].setData(1.2, -2.8);
    numberArray[2].setData(-5.0, 0.0);

    // Displaying the small array of complex numbers
    std::cout << "--- List of Complex Numbers ---" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Number " << (i + 1) << ": ";
        numberArray[i].display();
        std::cout << std::endl;
    }

    return 0;
}

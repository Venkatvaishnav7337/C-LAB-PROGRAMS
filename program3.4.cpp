#include <iostream>
#include <stdexcept> // For standard exceptions

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor to initialize default values
    Rectangle() : length(1.0), width(1.0) {}

    // Constructor with parameters
    Rectangle(double l, double w) {
        setLength(l);
        setWidth(w);
    }

    // Setter for length with validation
    void setLength(double l) {
        if (l < 0) {
            throw std::invalid_argument("Length cannot be negative.");
        }
        length = l;
    }

    // Setter for width with validation
    void setWidth(double w) {
        if (w < 0) {
            throw std::invalid_argument("Width cannot be negative.");
        }
        width = w;
    }

    // Getter for length
    double getLength() const {
        return length;
    }

    // Getter for width
    double getWidth() const {
        return width;
    }

    // Getter for Area
    double getArea() const {
        return length * width;
    }

    // Getter for Perimeter
    double getPerimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    try {
        std::cout << "--- Creating a Valid Rectangle ---" << std::endl;
        Rectangle rect(5.5, 4.0);
        std::cout << "Length: " << rect.getLength() << std::endl;
        std::cout << "Width: " << rect.getWidth() << std::endl;
        std::cout << "Area: " << rect.getArea() << std::endl;
        std::cout << "Perimeter: " << rect.getPerimeter() << "\n\n";

        std::cout << "--- Modifying with Valid Values ---" << std::endl;
        rect.setLength(10.0);
        rect.setWidth(3.5);
        std::cout << "New Area: " << rect.getArea() << std::endl;
        std::cout << "New Perimeter: " << rect.getPerimeter() << "\n\n";

        std::cout << "--- Attempting Invalid Value ---" << std::endl;
        rect.setLength(-2.5); // This will trigger the exception
        
    } catch (const std::invalid_argument& e) {
        std::cerr << "✅ Validation Error caught successfully: " << e.what() << std::endl;
    }

    return 0;
}

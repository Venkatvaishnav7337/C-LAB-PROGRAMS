#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int rows;
    int cols;
    int** data; // Pointer to a pointer to allocate the 2D grid

    // Helper method to allocate memory
    void allocateMemory() {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]{0}; // Initializes elements to 0
        }
    }

    // Helper method to free memory
    void freeMemory() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

public:
    // Parametric Constructor
    Matrix(int m, int n) : rows(m), cols(n) {
        if (m <= 0 || n <= 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than zero.");
        }
        allocateMemory();
    }

    // ✅ Deep Copy Constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocateMemory(); // Allocate new distinct block of memory
        
        // Deep copy values from the original matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Destructor to prevent memory leaks
    ~Matrix() {
        freeMemory();
    }

    // Method to set data at a specific coordinate
    void setValue(int r, int c, int value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = value;
        } else {
            throw std::out_of_range("Index out of bounds.");
        }
    }

    // Method to print the matrix layout
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    try {
        std::cout << "Creating original 2x3 Matrix (mat1)..." << std::endl;
        Matrix mat1(2, 3);
        mat1.setValue(0, 0, 10);
        mat1.setValue(0, 1, 20);
        mat1.setValue(0, 2, 30);
        mat1.setValue(1, 0, 40);
        mat1.setValue(1, 1, 50);
        mat1.setValue(1, 2, 60);
        
        std::cout << "mat1 Content:" << std::endl;
        mat1.display();

        std::cout << "\nInvoking Deep Copy Constructor to create mat2..." << std::endl;
        Matrix mat2 = mat1; // Triggers the deep copy constructor

        std::cout << "Modifying mat1 to prove separation of memory..." << std::endl;
        mat1.setValue(0, 0, 999);

        std::cout << "\nmat1 Content (Modified):" << std::endl;
        mat1.display();

        std::cout << "\nmat2 Content (Stays intact due to Deep Copy):" << std::endl;
        mat2.display();

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

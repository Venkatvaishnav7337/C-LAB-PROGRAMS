#include <iostream>
#include <stdexcept>

class Stack {
private:
    int* buffer;      // Dynamic array to store stack elements
    int capacity;     // Maximum number of elements the stack can hold
    int topIndex;     // Index of the top element (-1 when empty)

public:
    // Constructor to initialize the stack with a specific capacity
    Stack(int size) {
        if (size <= 0) {
            throw std::invalid_argument("Stack capacity must be greater than zero.");
        }
        capacity = size;
        buffer = new int[capacity]; // Allocate dynamic array memory
        topIndex = -1;              // Stack is initially empty
    }

    // Destructor to safely free up the allocated buffer memory
    ~Stack() {
        delete[] buffer;            // Release memory to prevent memory leaks
        buffer = nullptr;
    }

    // Method to insert an element onto the stack
    void push(int value) {
        if (topIndex >= capacity - 1) {
            throw std::overflow_error("Stack Overflow! Cannot push into a full stack.");
        }
        buffer[++topIndex] = value; // Increment top index and store value
    }

    // Method to remove and return the top element from the stack
    int pop() {
        if (topIndex < 0) {
            throw std::underflow_error("Stack Underflow! Cannot pop from an empty stack.");
        }
        return buffer[topIndex--];  // Return value and decrement top index
    }

    // Method to view the top element without removing it
    int peek() const {
        if (topIndex < 0) {
            throw std::underflow_error("Stack is empty. Nothing to peek.");
        }
        return buffer[topIndex];
    }

    // Helper method to check if stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }
};

int main() {
    try {
        std::cout << "Initializing a stack with a capacity of 3 items..." << std::endl;
        Stack elements(3);

        // Pushing elements onto the stack
        std::cout << "Pushing: 10, 20, 30" << std::endl;
        elements.push(10);
        elements.push(20);
        elements.push(30);

        // Uncommenting the next line will trigger a Stack Overflow exception
        // elements.push(40); 

        std::cout << "Current top item (peek): " << elements.peek() << std::endl;

        // Popping elements off the stack
        std::cout << "\nPopping items sequentially:" << std::endl;
        while (!elements.isEmpty()) {
            std::cout << "Popped: " << elements.pop() << std::endl;
        }

        // Uncommenting the next line will trigger a Stack Underflow exception
        // elements.pop();

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // The destructor gets implicitly executed here as 'elements' goes out of scope,
    // safely wiping the dynamic buffer from memory.
    std::cout << "\nStack went out of scope. Memory cleared safely." << std::endl;
    return 0;
}

#include <iostream>

class Counter {
private:
    int count;

public:
    // Constructor to initialize the counter to 0
    Counter() : count(0) {}

    // Increment the counter by 1
    void increment() {
        count++;
    }

    // Reset the counter back to 0
    void reset() {
        count = 0;
    }

    // Get the current value of the counter
    int get() const {
        return count;
    }
};

int main() {
    // Create an array of 3 Counter objects
    const int ARRAY_SIZE = 3;
    Counter counters[ARRAY_SIZE];

    std::cout << "--- Initial State ---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Counter " << i << " value: " << counters[i].get() << std::endl;
    }

    std::cout << "\n--- Exercising the Counters ---" << std::endl;
    
    // Increment Counter 0 twice
    counters[0].increment();
    counters[0].increment();

    // Increment Counter 1 five times
    for (int i = 0; i < 5; i++) {
        counters[1].increment();
    }

    // Increment Counter 2 once
    counters[2].increment();

    // Display values after increments
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Counter " << i << " after increments: " << counters[i].get() << std::endl;
    }

    std::cout << "\n--- Resetting Counter 1 ---" << std::endl;
    counters[1].reset();
    std::cout << "Counter 1 value after reset: " << counters[1].get() << std::endl;
    std::cout << "Counter 0 value remains: " << counters[0].get() << std::endl;

    return 0;
}

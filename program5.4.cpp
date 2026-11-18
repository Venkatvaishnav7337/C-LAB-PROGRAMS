
#include <iostream>
using namespace std;

class Counter {
    static int totalCreated;
    static int alive;

public:
    Counter() {
        totalCreated++;
        alive++;
    }

    ~Counter() {
        alive--;
    }

    static void display() {
        cout << "Total objects created: " << totalCreated << endl;
        cout << "Objects currently alive: " << alive << endl;
    }
};

int Counter::totalCreated = 0;
int Counter::alive = 0;

int main() {
    Counter c1, c2;

    Counter::display();

    {
        Counter c3;
        Counter::display();
    }

    cout << "\nAfter c3 is destroyed:\n";
    Counter::display();

    return 0;
}

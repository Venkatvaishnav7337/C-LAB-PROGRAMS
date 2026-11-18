
#include <iostream>
using namespace std;

class Tracer {
private:
    int id;

public:
    Tracer(int n) {
        id = n;
        cout << "Tracer " << id << " created." << endl;
    }

    ~Tracer() {
        cout << "Tracer " << id << " destroyed." << endl;
    }
};

int main() {
    const int N = 5;

    cout << "Creating Tracer objects...\n";

    for (int i = 1; i <= N; i++) {
        Tracer* t = new Tracer(i);

        // Uncomment the next line to prevent memory leaks
        delete t;
    }

    cout << "Program finished.\n";

    return 0;
}

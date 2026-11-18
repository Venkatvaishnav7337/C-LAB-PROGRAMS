
#include <iostream>
using namespace std;

class Money {
    int rupees, paise;

public:
    Money(int r = 0, int p = 0) {
        int total = r * 100 + p;
        rupees = total / 100;
        paise = total % 100;
    }

    Money operator+(Money m) {
        return Money(0, rupees * 100 + paise
                        + m.rupees * 100 + m.paise);
    }

    Money operator-(Money m) {
        int a = rupees * 100 + paise;
        int b = m.rupees * 100 + m.paise;

        if (a < b) {
            cout << "Error: Negative money result!\n";
            return Money();
        }

        return Money(0, a - b);
    }

    void display() {
        cout << "Rs. " << rupees << ".";
        if (paise < 10)
            cout << "0";
        cout << paise << endl;
    }
};

int main() {
    Money m1(10, 75);
    Money m2(5, 50);

    Money sum = m1 + m2;
    Money diff = m1 - m2;

    cout << "First amount: ";
    m1.display();

    cout << "Second amount: ";
    m2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    return 0;
}


#include <iostream>
#include <numeric>
#include <cstdlib>
using namespace std;

class Fraction {
    int num, den;

public:
    Fraction(int n = 0, int d = 1) {
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }

        if (d < 0) {
            n = -n;
            d = -d;
        }

        int g = gcd(abs(n), d);
        num = n / g;
        den = d / g;
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        int n, d;
        in >> n >> d;

        if (in && d == 0) {
            in.setstate(ios::failbit);
            return in;
        }

        if (in)
            f = Fraction(n, d);

        return in;
    }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.num << "/" << f.den;
        return out;
    }
};

int main() {
    Fraction f;

    cout << "Enter numerator and denominator: ";
    if (cin >> f)
        cout << "Simplified fraction: " << f << endl;
    else
        cout << "Invalid input! Denominator must not be zero.\n";

    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

const double coefficient = 1.067395682; // sin(108) / sin(63)
double F;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> F) {
        cout << fixed << setprecision(10) << coefficient * F << endl;
    }
    return 0;
}

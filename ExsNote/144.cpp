#include <iostream>

using namespace std;

int main() {
    double r;
    cin >> r;
    double area = 3.1416*r*r;

    cout.precision(2);
    cout << fixed << area << endl;
    return 0;
}

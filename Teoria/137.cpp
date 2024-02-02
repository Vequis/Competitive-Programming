#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x,y;
    cin >> x >> y;

    double pot = pow(x,y);
    cout.precision(4);
    cout << fixed << pot << endl;

    return 0;
}

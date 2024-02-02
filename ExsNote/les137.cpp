#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x,y;
    cin >> x >> y;
    double exp = pow(x,y);

    cout.precision(4);
    cout << fixed << exp << endl;
    return 0;
}

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main() {

    double soma = 0;
    long  n;
    cin >> n;

    int resp = (lgamma(n+1) / log(10)) + 1;
    cout << resp << endl;
    return 0;

}

#include <iostream>

using namespace std;

int main() {
    double a,b;

    cin >> a >> b;

    int div = a/b;

    int resp = a - b*div;

    cout << resp << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    char op;
    double n1,n2;
    cin >> op >> n1 >> n2;

    cout.precision(2);
    if (op == 'M') cout << fixed << n1*n2 << endl;
    else if (op == 'D') cout << fixed << n1/n2 << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    string op;
    double a,b;

    cin >> op >> a >> b;

    cout.precision(2);

    if(op=="M") cout << fixed << a*b << endl;
    else if (op=="D") cout << fixed << a/b << endl;

    return 0;
}

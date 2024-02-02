#include <iostream>

using namespace std;

int main() {
    int n,p,q,res;;
    string op;
    cin >> n >> p >> op >> q;

    if (op=="+") res = p+q;
    else if (op=="*") res = p*q;

    if (res > n) cout << "OVERFLOW" << endl;
    else if (res<=n) cout << "OK" << endl;

    return 0;
}

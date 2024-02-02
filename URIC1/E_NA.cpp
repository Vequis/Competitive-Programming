#include <iostream>

using namespace std;

int main() {

    int x;
    cin >> x;

    int resp = x - 9;

    if (resp < 0) {
        resp+=24;
    }

    cout << resp << endl;
    return 0;
}

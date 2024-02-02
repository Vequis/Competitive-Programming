#include <iostream>

using namespace std;

int main() {
    int n, d, a;

    cin >> n >> d >> a;

    int movs;

    if (d>=a){
        movs = d-a;
    } else if (d<a){
        movs = n - a + d;
    }

    cout << movs << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int d;
    cin >>d;
    int pont;
    if (d<=800) pont=1;
    else if (d<=1400) pont=2;
    else pont=3;

    cout << pont << endl;
    return 0;
}

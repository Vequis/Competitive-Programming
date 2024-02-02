#include <iostream>

using namespace std;

int main() {
    int l1,c1,l2,c2;
    cin >> l1 >> c1 >> l2 >> c2;

    cout << max(l1*c1,l2*c2) << endl;
    return 0;
}

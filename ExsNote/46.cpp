#include <iostream>

using namespace std;

int main() {
    int l,r,d;
    cin >> l >> r >> d;

    if (r>50 && l<r && r>d){
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}

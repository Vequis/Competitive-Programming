#include <iostream>

using namespace std;

int main() {
    int x,y;
    cin >> x >> y;

    if ((x>=0 and x<=432)and(y>=0 and y<=468)) {
        cout << "dentro" << endl;
    }else {
        cout << "fora" << endl;
    }
}

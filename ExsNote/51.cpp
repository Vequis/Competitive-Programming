#include <iostream>

using namespace std;

int main() {
    int p,d1,d2;
    cin >>p >> d1 >> d2;

    bool ganhador;

    if ((d1+d2)%2==0){
        ganhador = p;
    } else {
        ganhador = 1-p;
    }

    cout << ganhador << endl;
    return 0;
}

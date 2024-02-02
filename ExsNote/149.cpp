#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int ha,ma,hr,mr;

    cin >> ha >> ma >> hr >> mr;

    int intervalo;

    if (ma>mr){
        intervalo = (hr-ha)*60 - (ma-mr);
    } else {
        intervalo = (hr-ha)*60 + (mr-ma);
    }

    if (intervalo>=45) {
        cout << "Sucesso" << endl;
    } else if (intervalo < 45) {
        cout << "Atrasado " << 45-intervalo << endl;
    }
    return 0;

}

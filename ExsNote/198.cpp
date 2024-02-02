#include <iostream>

using namespace std;

int main() {
    int matriz[3][3];
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cin >> matriz[i][j];
        }
    }

    int soma = matriz[0][0] + matriz[0][1] + matriz[0][2];
    int var = 1;

    for (int i=0;i<3;i++) {
        int a = 0;
        int b = 0;
        for (int j=0;j<3;j++) {
            a+=matriz[i][j];
            b+=matriz[j][i];
        }
        if ((a!= soma) or (b!=soma)) var = 0;
    }

    int a=0;
    int b=0;
    for (int i=0;i<3;i++){
        a+=matriz[i][i];
        b+=matriz[i][2-i];
    }

    if ( (a!=soma) or (b!=soma) )var = 0;

    if (var == 1) cout << "SIM" << endl;
    else if(var==0) cout << "NAO" << endl;

    return 0;
}

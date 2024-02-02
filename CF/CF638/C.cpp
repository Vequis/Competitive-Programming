#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;

        int cont = 0; //Verificar isso daqui

        int p=1; int m=1;
        while (true) {

            if (n>= m+p && n<= m+2*p){
                cont++;
                cout << cont << endl;
                break;
            } else {
                cout << m << endl;
                p*=2;
                m+=p;

                cout << endl;
                cout << "Teste " << cont << endl;
                cout << "n : " << n << endl;
                cout << m+p << "   -   " << m+2*p << endl;
                cont++;
                if (cont>10) break;
            }
        }
    }
    return 0;

}


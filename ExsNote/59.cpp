#include <iostream>

using namespace std;

int main() {
    int ia,ib,fa,fb;

    cin >> ia >> ib >> fa >> fb;

    int cont = 0;

    if (ib != fb) {
        ib = fb;
        ia = 1-ia;
        cont++;
    }

    if (ia!=fa){
        cont++;
        ia = fa;
    }

    cout << cont << endl;
    return 0;
}

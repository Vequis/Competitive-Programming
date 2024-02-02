#include <iostream>

using namespace std;

int main() {
    int c,a;

    cin >> c >> a;

    int cont = 0;
    while (a>0){
        a-=(c-1);
        cont++;
    }

    cout << cont << endl;
    return 0;
}

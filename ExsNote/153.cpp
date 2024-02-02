#include <iostream>

using namespace std;

int main() {
    int n;
    int cont=0;

    while(true) {
        cin >> n;
        if (n==2018){
            break;
        }
        cont++;
    }

    cout << cont << endl;
    return 0;
}

#include <iostream>

using namespace std;

int collatz(int n){
    if (n%2==0){
        return n/2;
    } else {
        return 3*n + 1;
    }
}

int main() {
    int n;
    cin >> n;

    int cont = 0;
    while (n!=1){
        n = collatz(n);
        cont++;
    }

    cout << cont << endl; return 0;
}

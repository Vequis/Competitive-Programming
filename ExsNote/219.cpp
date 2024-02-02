#include <iostream>

using namespace std;

int main() {
    int soma = 0;
    int num;
    for (int i=0; i < 4 ; i++ ){
        cin >> num;
        soma += num;
    }

    cout << soma-3 << endl;
    return 0;
}

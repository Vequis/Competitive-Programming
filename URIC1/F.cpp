#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double soma = 0;
    long  n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        soma+=log(i);
    }

    soma /= log(10);

    int resp = soma+1;
    cout << resp << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    double n1,n2;
    cin >> n1 >> n2;
    double notafinal = (2*n1 + 3*n2)/5;

    if (notafinal>=7) cout <<"Aprovado" << endl;
    else if (notafinal<3) cout << "Reprovado" << endl;
    else cout << "Final" << endl;

    return 0;
}

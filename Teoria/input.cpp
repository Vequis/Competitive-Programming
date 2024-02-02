#include <iostream>

using namespace std;

int main() {

    double raio;
    cin >> raio;

    double pi =3.14159;

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << "A area eh " << raio*raio*pi << "\n" ;

    return 0;

}

#include <iostream>
#include <string>

using namespace std;

class Relogio{
public:
    int hora, minuto = 0;
};

int main() {

    Relogio *r1 = new Relogio;

    r1->minuto = 3;
    r1->hora = 35;

    cout << *r1 << endl;

    delete r1;

    cout << *r1 << endl;

    return 0;
}
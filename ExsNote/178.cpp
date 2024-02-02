#include <iostream>

using namespace std;

int main() {
    int d1,h1,m1;
    int d2,h2,m2;

    cin >> d1 >> h1 >> m1 >> d2 >> h2 >> m2;

    int deltaD = d2-d1;
    if (deltaD<0) deltaD+=365;

    int deltaH = h2-h1;
    if(deltaH<0)  {
        deltaH+=24;
        deltaD--;
    }

    int deltaM = m2-m1;
    if(deltaM<0) {
        deltaM+=60;
        deltaH--;
    }

    int qtdSeg = 60*(deltaM + 60*(deltaH + 24*(deltaD)));

    cout << qtdSeg << endl; return 0;
}

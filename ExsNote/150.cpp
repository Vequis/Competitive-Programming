#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    int maior = a+b+c+c+abs(a-b)+abs(a+b+abs(a-b) -2*c);
    maior/=4;

    cout << maior << endl;
}

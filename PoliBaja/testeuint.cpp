#include <iostream>

using namespace std;

string converteBinario(int a) {
    string s = "";

    while (a>0) {
        s = (char)('0' + a%2) + s;
        a/=2;
    }

    while( (int)s.size() < 8) {
        s = '0' + s;
    }

    return s;
}

int main() {

    char x1, x2;
    uint16_t y1;

    y1 = 52345;

    x1 = (char)(y1>>8);
    x2 = (char)(y1 % (1<<8));

    cout << converteBinario(y1) << endl;
    cout << converteBinario(x1 + 256);
    cout << converteBinario(x2) << endl;
    
}
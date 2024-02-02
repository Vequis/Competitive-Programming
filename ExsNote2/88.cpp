#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;

    if ((a==b)and(a!=c)) {cout << "C" << endl;}
    else if ((a==c)and(a!=b)) {cout << "B" << endl;}
    else if ((b==c)and(a!=c)) {cout << "A" << endl;}
    else if ((a==c)and(b==c)) {cout << "*" << endl;}

    return 0;

}

#include <iostream>

using namespace std;

int main() {

    int a, b, c;
    bool var=true;

    cin >> a >> b >> c;

    while (var){
        var = false;

        int temp;
        if (a>b){
            temp = b;
            b=a;
            a=temp;
            var=true;
        }

        if (b>c){
            temp = c;
            c=b;
            b=temp;
            var=true;
        }

    }

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}

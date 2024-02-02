#include <iostream>

using namespace std;

int main(){

    int x, y;
    int a, b;

    cin >> x >> y;

    if (x*4 < y){
         cout << "No" << endl;
        return 0;
    }
    else if (y < 2*x) {
        cout << "No" << endl;
        return 0;
    }

    if ((y - 2*x)%2 == 0){
        b = (y-2*x)/2;
    } else {
        cout << "No" << endl;
        return 0;
    }

    if ((y-4*b)%2 == 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;

}
#include <iostream>

using namespace std;

int main(){

    int x;
    for (int i=0; i<5 ; i++) {
        int num;
        cin >> num;
        if (num == 0)x = i+1;
    }

    cout << x << endl;

}
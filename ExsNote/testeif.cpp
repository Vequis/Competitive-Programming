#include <iostream>

using namespace std;

int main() {

    for (int i=0; i<100; i++){
        if (i<20) {
            cout << "-";
        } else {
            break;
        }
        cout << i << endl;
    }

}

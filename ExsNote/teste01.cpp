#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int m[10][10];

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            m[i][j] = 10-j;
        }
    }

    for (int i=0; i<10; i++){
        cout << m[0][i] << endl;
    }
    cout << endl;

    sort(m[0],m[0]+10);

    for (int i=0; i<10; i++){
        cout << m[0][i] << endl;
    }
    return 0;
}

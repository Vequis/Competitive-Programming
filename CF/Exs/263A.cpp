#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int resp;

    for (int i=1; i<=5; i++){
        for (int j=1; j<=5; j++) {
            int num;
            cin >> num;
            if (num==1){
                resp = abs(i-3) + abs(j-3);
            }
        }
    }

    cout << resp << endl;
    return 0;
}

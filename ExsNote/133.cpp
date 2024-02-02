#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool acesoA = false;
    bool acesoB = false;

    int ac;
    for (int i=1;i <= n;i++){

        cin >> ac;
        if (ac == 1) {
            acesoA = !acesoA;
        } else if(ac == 2) {
            acesoA = !acesoA;
            acesoB = !acesoB;
        }

    }
    cout << acesoA << "\n" << acesoB << "\n";
}

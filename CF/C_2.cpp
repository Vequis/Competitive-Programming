#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int t;
    cin >> t;
    long long int p;

    for (int i=0; i<t; i++) {
        int n, k;
        cin >> n >> k;
        int j = floor((k)/(n-1));


        if (k%(n-1)==0) {
            p = j*n - 1;
        } else {
            p = j*n + k%(n-1);
        }
        cout << p << endl;
    }

    return 0;
}

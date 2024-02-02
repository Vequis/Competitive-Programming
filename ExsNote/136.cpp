#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n;
    float num;
    cin >> n;

    for (int i =1; i <= n; i++) {
        cin >> num;

        cout.precision(4);
        cout << fixed << pow(num, 0.5) << endl;
    }

}

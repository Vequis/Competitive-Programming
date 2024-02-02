#include <iostream>

using namespace std;

int func (int n, int k) {

    int x = n/2;
    int y = n - x;

    if (n <= k) return 1;
    else return func(x, k) + func(y, k);
}

int main() {

    int num;
    cin >> num;
    int k;
    cin >> k;

    while (num!=0 && k!=0){
        cout << func(num, k) << endl;
        cin >> num >> k;
    }

    return 0;
}

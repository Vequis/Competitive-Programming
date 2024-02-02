#include <iostream>

using namespace std;

int S(int n){
    if (n==1) {
        return 1;
    } else {
        return S(n-1) + n;
    }
}

int main() {
    int n;
    cin >> n;
    cout << S(n) << endl;

    return 0;
}

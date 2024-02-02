#include <iostream>

using namespace std;

int main() {

    int n;

    cin >> n;

    bool ok = true;

    for (int i=0; i < n; i++) {
        int num;
        cin >> num;

        if (num==1){
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "EASY" << endl;
    } else {
        cout << "HARD" << endl;
    }
    return 0;
}

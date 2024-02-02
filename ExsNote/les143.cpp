#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string gab, res;
    cin >> gab >> res;
    int nota = 0;

    for (int i=0;i<n;i++) {
        if (gab[i]==res[i]) nota++;
    }

    cout << nota << endl;
    return 0;
}

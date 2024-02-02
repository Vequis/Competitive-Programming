#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int k;
    cin >> k;

    string s;
    cin >> s;

    int sz = (int)s.size();

    if(sz<=k) {
        cout << s << endl;
    } else {
        for (int i=0; i<k; i++) {
            cout << s[i];
        }
        cout << "..." << endl;
    }

    return 0;
}


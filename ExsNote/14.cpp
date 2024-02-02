#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int v[3],h,l;
    cin >> v[0] >> v[1] >> v[2] >> h >> l;

    sort (v,v+3);

    if (v[0] <= min(h,l) and v[1]<=max(h,l)){
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}

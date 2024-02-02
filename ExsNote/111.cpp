#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int v[3];
    cin >> v[0] >> v[1] >> v[2];

    sort(v,v+3);

    if ( v[0]+v[1]==v[2] or v[0]==v[1] or v[1] == v[2]){
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}

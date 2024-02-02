#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int rx = 0;
    int ry = 0;
    int rz = 0;

    for (int i=0; i<n; i++){
        int x, y ,z;
        cin >> x >> y >> z;
        rx+=x; ry+=y; rz+=z;
    }

    if (ry==0 and rx==0 and rz==0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

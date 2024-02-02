#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int  v[3];
    cin >> v[0] >> v[1] >> v[2];
    sort(v, v+3);

    if (v[0]==5 and v[1]==5 and v[2] == 7){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;

}


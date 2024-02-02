#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int v[10];

    for (int i=0;i<10;i++) {
        cin >> v[i];
    }
    for (int i=0;i<10;i++){
        if(v[i]%2==0) cout << v[i] << " ";
    }
    cout<<endl;
    for (int i=0;i<10;i++){
        if(abs(v[i]%2)==1) cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}

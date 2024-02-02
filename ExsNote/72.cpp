#include <iostream>

using namespace std;

int main() {
    int v[4];

    for (int i=0;i<4;i++){
        cin >> v[i];
    }

    int dist;
    for (int i=0; i<2; i++){
        for (int d=2; d<=3; d++){
            if (v[i] == v[i+d]){
                if (d==2){
                    cout << "V" << endl;
                } else if(d==3 and i==0){
                    cout << "F" << endl;
                }
            }
        }
    }
    return 0;
}

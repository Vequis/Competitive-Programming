#include <iostream>

using namespace std;

int main() {
    int h,f,p,d;
    cin >> h >> p >> f >> d;

    for (int i=f;i<30;i+=d){
        if (i==h){
            cout << "S" << endl;
            break;
        } else if (i==p){
            cout << "N" << endl;
            break;
        } else if (i==15 and d==1) {
            i = -1;
        } else if (i==0 and d==-1) {
            i = 16;
        }
    }

}

#include <iostream>

using namespace std;

int main() {
    int l1,l2,c1,c2;

    cin >> l1 >> l2;
    cin >> c1 >> c2;

    int pontL, pontC;

    if (l1==l2){
        pontL = 2*(l1+l2);
    } else if (l1==(l2+1) or l1==(l2-1)){
        pontL = 3*(l1+l2);
    } else {
        pontL = (l1+l2);
    }

    if (c1==c2){
        pontC = 2*(c1+c2);
    } else if (c1==(c2+1) or c1==(c2-1)){
        pontC = 3*(c1+c2);
    } else {
        pontC = (c1+c2);
    }

    if(pontL > pontC){
        cout << "Lia" << endl;
    } else if (pontC > pontL){
        cout << "Carolina" << endl;
    }else if (pontL==pontC)cout << "empate" << endl;

    return 0;
}

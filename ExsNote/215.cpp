#include <iostream>

using namespace std;

int main() {
    int A[3],B[3];
    cin >> A[0] >> A[1] >> A[2];
    cin >> B[0] >> B[1] >> B[2];

    for (int i=0; i<3; i++){
        if (A[i]>B[i]){
            cout << "A" << endl;
            break;
        } else if (A[i] < B[i]) {
            cout << "B" << endl;
            break;
        }
    }
    return 0;
}

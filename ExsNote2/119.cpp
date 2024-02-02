#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    int hMax=1;
    int var=1;

    //Lendo os valores;
    for (int i=0;i<n;i++){
        cin >> A[i];
    }

    for (int i=0;i<n;i++) {
        if ((i+1>=hMax+1)and(n-i>=hMax+1)) {
            for (int j=0;j<hMax+1;j++){
                if((A[i-j]<hMax+1-j)or(A[i+j]<hMax+1-j)){
                    var=0;
                }
            }
        }else {
            continue;
        }

        if ((var==1)){
            hMax++;
        }
        var = 1;
    }
    cout << hMax << endl;
    return 0;
}

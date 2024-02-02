#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;

    for (int i=0;i<t; i++){
        int n;
        cin >> n;

        int cont = 0;
        while (n!=1){
            if (n%3!=0){
                cont = -1;
                break;
            } else {
                if (n%2==0){
                    n/=6;
                    cont++;
                }
                else {
                    cont+=2;
                    n/=3;
                }
            }
            // cout << "A" << n << endl;
        }
        cout << cont << endl;
    }
    return 0;
}
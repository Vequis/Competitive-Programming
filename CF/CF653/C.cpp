#include <iostream>

using namespace std;

int main(){

    int contA;
    int contB;

    string s;

    int t;
    cin >> t;

    for (int i=0; i<t; i++){
        int num;
        cin >> num;
        cin >> s;

        contA=0;
        contB=0;

        int exc[num];

        int cont = 0;
        for (int i=0; i<num; i++){
            if (s[i] == '('){
                if (contB>contA){
                    exc[i] = contB-contA;
                } else {
                    exc[i] = 0;
                }
                contA++;
            }
            else {
                contB++;
                exc[i] = 0;
            }
        }

        for (int i=num-1; i>=0; i--){
            if (exc[i]-cont > 0){
                cont++;
            }
        }
        
        cout << cont << endl;
    }

    return 0;
}
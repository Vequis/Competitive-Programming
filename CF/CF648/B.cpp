#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;

        int vetor[n];
        int ordenado[n];

        int cont0 = 0;
        int cont1 = 0;

        for (int i=0; i<n; i++){ 
            int num;
            cin >> num;

            vetor[i] = num;
            ordenado[i] = num;
        }

        for (int i=0; i<n; i++) {
            int num;
            cin >> num;

            if (num==0) cont0++;
            else cont1++;
        }

        sort(ordenado, ordenado+n);

        bool ordem = true;
        for (int i=0; i<n;i++){
            if (ordenado[i] != vetor[i]) ordem = false;
        }        

        if (ordem==true or (ordem==false and (cont0>0 and cont1>0))) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n,b;
    string resposta="A";
    int cont=0;

    while (true) {
        cin >> n >> b;
        if (n==0 and b==0){
            break;
        }
        cont++;

        int v[91];

        for (int i=0; i<b; i++ ){
            cin >> v[i];
        }

        sort (v,v+b);

        for (int k=1; k<n; k++){
            bool var = 0;
            for(int i=0; i<b; i++){
                for (int j=0; j<b; j++){
                    if (i+j<=b-1){
                        if(v[i+j]-v[i]==k){
                            var = 1;
                            break;
                        }
                    }
                }
            }
            if (var == 0 and resposta[cont]!='N') {
                resposta[cont] = 'N';
            }
        }

        if (resposta[cont]!='N') {
            resposta[cont] = 'Y';
        }

    }

    for (int i=1;i<=cont; i++){
        cout << resposta[i] << endl;
    }

    return 0;
}

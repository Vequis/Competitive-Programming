#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int v[n];
    int contador = 0;

    bool frente = false;
    bool tras = false;

    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    for (int i=1; i<(n-1); i++){
        for (int j=1; j<n; j++){
            //Frente
            if(v[i+j]>v[i] and i+j<=n-1){
                frente = true;
            }

            if(v[i-j]>v[i] and i-j>=0){
                tras = true;
            }
        }
        if (tras and frente){
            contador ++;
        }

        frente = false;
        tras = false;
    }

    cout << contador << endl;
    return 0;
}

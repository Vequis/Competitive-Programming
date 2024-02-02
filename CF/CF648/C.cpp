#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
     
    int v1[n];
    int v2[n];

    for (int i=1; i<=n;i++){cin >> v1[i];}
    for (int i=1; i<=n;i++){cin >> v2[i];}

    int contMax= 0;
    for (int i=1; i<=n; i++){
        int cont = 0;

        for (int j=1; j<=n; j++) {
            
            int ind;
            if (j-i > 0) ind = j-i;
            else ind = n-i+j;
            
            if (v1[j] == v2[ind]) cont++;
        }

        if (cont > contMax) contMax = cont;
        if (cont == n) break;
    }

    cout << contMax << endl;
}


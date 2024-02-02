#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int bin[30];
    int cont=0;

    for(int i=0;i<30;i++){
        bin[i]=2;
    }

    while(n!=1){
        bin[cont] = (n%2);
        n = n/2;
        cont++;
    }
    bin[cont]=1;

    for(int i=29;i>=0;i--){
        if ((bin[i]==1)or(bin[i]==0)){
            cout << bin[i];
        }
    }
    cout << endl;
    return 0;
}

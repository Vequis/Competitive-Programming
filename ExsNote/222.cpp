#include <iostream>

using namespace std;

int intervalo(int h1,int m1,int h2,int m2){
    if (h1>h2){
        return 60*(h2-h1+24) + (m2-m1);
    } else if (h1==h2 and m1>m2){
        return 24*60 + m2-m1;
    } else {
        return 60*(h2-h1) + (m2-m1);
    }
}

int main(){
    int v[10005];
    int cont = 0;

    while (true){
        int h1,m1,h2,m2;
        cin >> h1 >> m1 >> h2 >> m2;
        if (h1==0 and m1==0 and h2==0 and m2==0){break;}
        v[cont] = intervalo(h1,m1,h2,m2);
        cont ++;
    }

    for (int i=0; i<cont; i++){
        cout << v[i] << endl;
    }
    return 0;
}

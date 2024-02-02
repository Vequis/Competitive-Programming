#include <iostream>

using namespace std;

int main(){
    char letra;
    cin >> letra;
    cout << letra << " = " << (int)(letra) << endl; //Operação CAST;

    //Metodo para comparar chars;

    if (letra == 'a'){
        //Condição qqr
        cout << letra << endl;
    }

    if ((letra >= 'a')and(letra <='z'))  {
        cout << "É letra minúscula";
    }
}

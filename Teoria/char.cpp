#include <iostream>

using namespace std;

int main(){
    char letra;
    cin >> letra;
    cout << letra << " = " << (int)(letra) << endl; //Opera��o CAST;

    //Metodo para comparar chars;

    if (letra == 'a'){
        //Condi��o qqr
        cout << letra << endl;
    }

    if ((letra >= 'a')and(letra <='z'))  {
        cout << "� letra min�scula";
    }
}

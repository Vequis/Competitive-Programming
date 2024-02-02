#include <iostream>
using namespace std;
int main() {
    float a,b;
    cin >> a >> b;
    float media = (a+b)/2;
    if (media >= 7){
        cout << "Aprovado";
    }else if(media >= 4){
        cout << "Recuperacao";
    }else{
        cout << "Reprovado";
    }
    cout << endl;
}

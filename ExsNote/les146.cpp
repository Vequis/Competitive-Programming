#include <iostream>

using namespace std;

int main() {
    string risada;
    cin >> risada;

    string vog="",gov="";

    for (int i=0;i<risada.size();i++){
        if ((risada[i]=='a')or(risada[i]=='e')or(risada[i]=='i')or(risada[i]=='o')or(risada[i]=='u')){
            vog += risada[i];
        }
        if ((risada[risada.size()-1-(i)]=='a')or((risada[risada.size()-1-(i)]=='e'))or((risada[risada.size()-1-(i)]=='i'))or((risada[risada.size()-1-(i)]=='o'))or((risada[risada.size()-1-(i)]=='u'))){
            gov += risada[risada.size()-1-i];
        }


    }
    if (vog == gov) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i=0; i<t; i++){

        string exp;
        cin >> exp;

        int cont = 0;

        int sz = (int)exp.size();

        for (int j=0; j<sz; j++){
            if (exp[j]!='0'){
                cont++;
            }
        }

        cout << cont << endl;

        for (int j=0; j<sz; j++){
            if (exp[j] != '0'){
                cout << exp[j];
                for (int k=0; k<sz-j-1;k++){
                    cout << "0";
                }

                cout << " ";
            }
        }

        cout << endl;

    }
    return 0;
}

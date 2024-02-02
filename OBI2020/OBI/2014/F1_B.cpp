#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int n;
    cin >> n;
    int h;
    cin >> h;

    int atual;
    int lido;

    int movs=0;

    cin >> atual;
    for (int i=2; i<=n; i++) {
        cin>>lido;

        int movsAtual = h-atual;
        atual = lido+movsAtual;
        movs+=abs(movsAtual);
    }

    cout << movs << endl;
    return 0;

}
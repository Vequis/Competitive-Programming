#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int soma=0;
    for (int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;

        soma+= y;
        soma-=x;
    }

    for (int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;

        soma+=x;
        soma-=y;
    }

    cout << soma << endl;
    return 0;
}
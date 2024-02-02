#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    int n, m;

    cin >> n >> m;

    long long int soma = 0;
    int ant = -1;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;

        num = min(num, m-num);

        if (num >= ant) {
            ant = num;
            soma+= num;
        } else if (m-num >= ant){
            ant = m-num;
            soma+=ant;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << soma << endl;
    return 0;
}
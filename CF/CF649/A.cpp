#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {

        int n, x;
        cin >> n >> x;

        int soma = 0;
        int ok = 0;
        int indMenor = n+1;
        int indMaior = -1;

        vector<int> V;
        for (int j=1; j<=n; j++){
            int num;
            cin >> num;
            soma+=(num%x);
            if (num%x != 0) {
                ok = 1;
                indMenor = min(j, indMenor);
                indMaior = max(j, indMaior);
            }
        }

        if (soma%x != 0){
            cout << n << endl;
        } else if (ok==1){
            cout << max( n-(indMenor), indMaior-1 ) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
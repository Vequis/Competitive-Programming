#include <iostream>

using namespace std;

int main() {
    int n,p;
    cin >> n >> p;
    int cont = 0;

    for (int i =0; i<n; i++){
        int a,b;
        cin >> a >> b;
        if (a+b >= p){
            cont ++;
        }
    }

    cout << cont << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a;
    int total = 0;
    int qtdDias = 0;

    int i = 1;
    while (i <= n){
        cin >> a;
        total+=a;
        if (total >= 1000000 && qtdDias == 0){
            qtdDias = i;
        }
        i++;
    }
    cout << qtdDias << "\n";
}

#include <iostream>

using namespace std;

int main() {
    int i = 1;
    int n;
    cin >> n;
    int l,c;
    int coposQuebrados = 0;

    while (i <= n){
        cin >> l >> c;

        if (l>c){
            coposQuebrados += c;
        }
        i++;
    }
    cout << coposQuebrados << "\n";
}

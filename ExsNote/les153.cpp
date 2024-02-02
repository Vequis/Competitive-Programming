#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int v[n],u[n];

    for (int i=0;i<n;i++) {
        cin >> v[i];
        u[i] = v[i];
    }

    sort(u,u+n);
    int a[n];

    int cont = 0;
    for (int i=0;i<n;i++){
        if (u[i] != v[i]){
            a[cont] = u[i];
            cont++;
        }
    }

    cout << cont << endl;
    for (int i=0;i<cont;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

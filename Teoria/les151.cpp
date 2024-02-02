#include <iostream>

using namespace std;

int hanoi(int n){
    if (n==1) {
        return 1;
    }

    return 2*hanoi(n-1) + 1;

}

int main(){
    int n, v[10005];

    int i = 1;
    while (true){
        cin >> v[i];
        if (v[i]==0){
            i--;
            break;
        }
        i++;
    }

    for (int j=1;j<=i;j++){
        cout << "Teste " << j << endl;
        cout << hanoi(v[j]) << endl << endl;
    }
}

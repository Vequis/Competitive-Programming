#include <iostream>

using namespace std;

int main() {
    int n,q,l[51],x[10001],num;
    cin >> n;

    for (int i=0;i<n;i++){
        cin >> l[i];
    }

    cin >> q;
    for (int i=0;i<q;i++){
        cin >> x[i];
    }


    for (int j=0;j<q;j++){
        int var = 1;
        for (int i=0;i<n;i++){
            if (x[j]==l[i]){
                var = 0;
                cout << "Sim" << endl;
                break;
            } else continue;
        }
        if (var == 1) cout << "Nao" << endl;
    }
    return 0;
}

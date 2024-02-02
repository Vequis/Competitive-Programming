#include <iostream>
#include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {

        int n,m;
        cin >> n>> m;

        vector<int> R;
        vector<int> C;

        R.resize(n+1);
        C.resize(m+1);

        for (int j=1; j<=n; j++) {
            for (int k=1; k<=m; k++) {
                int num;
                cin >> num;

                if (num == 1) {
                    R[j]++;
                    C[k]++; 
                }
            }
        }

        int cont1=0;
        int cont2 = 0;

        for (int j=1; j<=n; j++) if (R[j]==0) cont1++;
        for (int j=1; j<=m; j++) if (C[j]==0) cont2++; 

        if (min(cont1,cont2)%2==1){
            cout << "Ashish" << endl;
        } else {
            cout << "Vivek" << endl;
        }
    }
    return 0;

}
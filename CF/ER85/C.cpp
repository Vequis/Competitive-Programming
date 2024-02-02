#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a[300005];
int b[300005];

int main() {

    int t;
    cin >> t;
    vector<int> V;

    for (int i=0; i<t; i++) {

        int tiros = 0;

        int n;
        cin >> n;

        for (int j=0; j<n; j++){
            cin >> a[j] >> b[j];
            if (j>0) {
                if (a[j] > b[j-1]){
                    tiros += a[j]-b[j-1];
                    a[j]=b[j-1];
                }
            }
        }

        if (a[0] > b[n-1]){
            tiros += a[0] - b[n-1];
            a[0] = b[n-1];
        }

        sort(a, a+n);

        tiros+=a[0];
        V.push_back(tiros);
    }

    for (int i=0; i<t; i++) {
        cout << V[i] << endl;
    }
    return 0;
}

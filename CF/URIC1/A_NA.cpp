#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int v[n];

    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    long long int prod=1;

    long m = max(v[0]*v[1], v[n-3]*v[n-2]);

    prod *= v[n-1]*m;

    cout << prod << endl;
    return 0;

}

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int v[n];

    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    sort(v, v+n);

    cout << v[0] << endl;
    return 0;
}
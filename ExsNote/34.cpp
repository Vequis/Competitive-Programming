#include <iostream>
#include <algorithm>

using namespace std;

int ordem(int a, int b){
    return a>b;
}

int main() {
    int n, k;

    cin >> n >> k;
    int v[n];
#include <iostream>
#include <algorithm>

using namespace std;

int ordem(int a, int b){
    return a>b;
}

int main() {
    int n, k;

    cin >> n >> k;
    int v[n];

    for (int i=0; i<n; i++){
        cin >>v[i];
    }

    sort(v, v+n,ordem);

    while (v[k] == v[k-1]){
        k++;
    }
#include <iostream>
#include <algorithm>

using namespace std;

int ordem(int a, int b){
    return a>b;
}

int main() {
    int n, k;

    cin >> n >> k;
    int v[n];

    for (int i=0; i<n; i++){
        cin >>v[i];
    }

    sort(v, v+n,ordem);

    while (v[k] == v[k-1]){
        k++;
    }

    cout << k << endl;
    return 0;
}

    cout << k << endl;
    return 0;
}

    for (int i=0; i<n; i++){
        cin >>v[i];
    }

    sort(v, v+n,ordem);

    while (v[k] == v[k-1]){
        k++;
    }

    cout << k << endl;
    return 0;
}

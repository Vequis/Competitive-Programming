#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n,v[3];
    cin >> n >> v[0] >> v[1] >> v[2];

    sort(v,v+3);

    int cont=0;
    for (int i=0; i<3; i++){
        if (n>=v[i]){
            n-=v[i];
            cont++;
        } else if(n<v[i]) {
            break;
        }
    }
    cout << cont << endl;
    return 0;
}

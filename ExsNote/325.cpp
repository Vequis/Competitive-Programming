#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int v[1010];

    int tempo = 0;

    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i]-v[i-1]<=10 and i>0){
            tempo += v[i] - v[i-1];
        } else {
            tempo +=10;
        }
    }

    cout << tempo << endl;

    return 0;

}

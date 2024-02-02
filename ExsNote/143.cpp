#include <iostream>

using namespace std;

int main() {
    int v[6] = {100,50,25,10,5,1};

    int n;
    cin >> n;
    int total = 0;

    for(int i=0; i<6; i++){
        int temp = (n/v[i]);
        n-=temp*(v[i]);
        v[i] = temp;
        total+= temp;
    }

    cout << total << endl;
    for(int i=0; i<6;i++){
        cout << v[i] << endl;
    }
    return 0;
}
